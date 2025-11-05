#https://www.python.org/jobs/
from bs4 import BeautifulSoup
import requests
import csv
import pandas as pd
from fake_useragent import UserAgent
jobs=[]
ua = UserAgent()
header = {'user-agent':ua.chrome}
base_url = 'https://www.python.org/jobs/'
soup = BeautifulSoup(requests.get(base_url,headers = header).content,'lxml')
for page in range(1,5):
  url = base_url + '?page=' + str(page)
  soup = BeautifulSoup(requests.get(url,headers = header).content,'lxml')
  titles = soup.find_all('span', class_='listing-company-name')
  locations = soup.find_all('span', class_='listing-location')
  dates = soup.find_all('span',class_='listing-posted')
  categories = soup.find_all('span',class_='listing-company-category')
  skill_sets = soup.find_all('span',class_='listing-job-type')
  for title, loc,category,skill_set,date in zip(titles,locations,categories,skill_sets,dates):
    clean_title = " ".join(title.text.split())
    if clean_title.startswith("New"):
       clean_title = clean_title[3:].strip()
    link_tag = title.find('a')
    job_link = "https://www.python.org" + link_tag['href'] if link_tag else "N/A"
    print(clean_title)
    print("".join(skill_set.text).strip())
    print(loc.text)
    print(date.text)
    print(category.text)
    print(job_link)
    if job_link != "N/A":
      job_page = BeautifulSoup(requests.get(job_link, headers=header).content, 'lxml')
      ul = job_page.find('h2', string='Contact Info').find_next('ul')
      for li in ul.find_all('li'):
        print(li.get_text(strip=True))
      print("-" * 100)
    job_data = {
        'Job Role' : clean_title,
        'Requirements': ("".join(skill_set.text).strip()),
        'Location': loc.text,
        'Date': date.text,
        'Category': category.text,
        'Link': job_link,
        'Contact Details':li.get_text(strip=True)
    }
    jobs.append(job_data)
    df = pd.DataFrame(jobs)
    df.to_csv('jobs.csv', index=False, encoding='utf-8')
    with open('jobs.json', 'w', encoding='utf-8') as json_file:
      df.to_json(json_file, orient='records', lines=True)




#books.toscrape.com
from bs4 import BeautifulSoup
import requests
import csv
import pandas as pd
from fake_useragent import UserAgent

ua = UserAgent()
header = {'user-agent':ua.chrome}


base_url = 'http://books.toscrape.com/catalogue/page-{}.html'
all_books = []

for page in range(1, 51):
    url = base_url.format(page)
    response = requests.get(url,headers = header)
    soup = BeautifulSoup(response.content, 'lxml')

    books = soup.find_all('article', class_='product_pod')

    for book in books:
        title = book.h3.a['title']
        price = book.find('p', class_='price_color').text.replace('Â', '')
        rating = book.p['class'][1]
        link = book.h3.a['href']
        full_link = 'http://books.toscrape.com/catalogue/' + link

        book_data = {
            'title': title,
            'price': price,
            'rating': rating,
            'link': full_link
        }

        all_books.append(book_data)


df = pd.DataFrame(all_books)
df.to_csv('books_data.csv', index=False, encoding='utf-8')
with open('books_data.json', 'w', encoding='utf-8') as json_file:
    df.to_json(json_file, orient='records', lines=True)







#https://pythonjobs.github.io/
from bs4 import BeautifulSoup
import requests
import csv
import json
import pandas as pd
from fake_useragent import UserAgent
ua = UserAgent()
header = {'user-agent':ua.chrome}
base_url = 'https://pythonjobs.github.io/'
soup = BeautifulSoup(requests.get(base_url,headers = header).content,'lxml')
#print(soup)
jobs = []
job_cards = soup.find_all('section',class_='job_list')
for job in job_cards:
  titles = job.find_all('h1')
  locations = [span for span in job.find_all("span", class_="info") if span.find("i", class_="i-globe")]
  dates = [span for span in job.find_all("span",class_="info") if span.find("i",class_="i-calendar")]
  companies = [span for span in job.find_all("span",class_="info") if span.find("i",class_="i-company")]
  links = job.find_all('a',class_="go_button")
  
  for title,loc,date,company,link in zip(titles,locations,dates,companies,links):
    print(title.text)
    print("".join(loc.text).strip())
    print("".join(date.text).strip())
    print("".join(company.text).strip())
    job_link = "https://pythonjobs.github.io/" + link.get('href') if links else "N/A"
    print(job_link)
    if job_link != "N/A":
      job_page = BeautifulSoup(requests.get(job_link, headers=header).content, 'lxml')
      contact_info_list = []
      contact_info = job_page.find_all('div',class_='field')
      for info in contact_info:
        text = info.get_text(strip=True)
        contact_info_list.append(text)
        print(contact_info_list)
      print("-"*100)
  
      jobs_data = {
          'Title': title.text,
          'Location': "".join(loc.text).strip(),
          'Date': "".join(date.text).strip(),
          'Company': "".join(company.text).strip(),
          'Link': job_link,
          'Contact Info': contact_info_list
        }
      jobs.append(jobs_data)
      pd.DataFrame(jobs).to_csv('jobs.csv', index=False, encoding='utf-8')
      with open('jobs.json', 'w', encoding='utf-8') as json_file:
        pd.DataFrame(jobs).to_json(json_file, orient='records', lines=True)

--------------------------------------------------------------------------------------------------------------------------------------




import scrapy
from bookstoscrape.items import BookstoscrapeItem

class BooksSpider(scrapy.Spider):
    name = "books"
    allowed_domains = ["books.toscrape.com"]
    start_urls = ["https://books.toscrape.com"]

    def parse(self, response):
        books = response.xpath('//article[@class="product_pod"]')
        for book in books:
            item = BookstoscrapeItem()
            relative_link = book.xpath('.//h3/a/@href').get()
            item['link'] = response.urljoin(relative_link)
            item['rating'] = book.xpath('.//p[contains(@class, "star-rating")]/@class').extract()
            item['price'] = book.xpath('.//*[@class="price_color"]/text()').extract()
            item['title'] = book.xpath('.//h3/a/@title').extract()
            yield item   

        next_page = response.xpath('//*[@class="next"]/a/@href').get()
        if next_page:
            yield response.follow(next_page,callback=self.parse)
        pass







from itemadapter import ItemAdapter
import sqlite3


class BookstoscrapePipeline:
    def open_spider(self, spider):
        # Connect (creates books.db if it doesn't exist)
        self.conn = sqlite3.connect("books.db")
        self.cur = self.conn.cursor()

        # Create the 'books' table if it doesn't exist
        self.cur.execute("""
            CREATE TABLE IF NOT EXISTS books(
                title TEXT,
                price TEXT,
                rating TEXT,
                link TEXT
            )
        """)
        self.conn.commit()

    def close_spider(self, spider):
        # Commit and close DB connection
        self.conn.commit()
        self.conn.close()

    def process_item(self, item, spider):
        adapter = ItemAdapter(item)

        # Extract values safely (convert lists to strings if needed)
        title = adapter.get('title')
        price = adapter.get('price')
        rating = adapter.get('rating')
        link = adapter.get('link')

        if isinstance(title, list):
            title = title[0]
        if isinstance(price, list):
            price = price[0]
        if isinstance(rating, list):
            rating = rating[0]

        # Insert item into the table
        self.cur.execute("""
            INSERT INTO books (title, price, rating, link)
            VALUES (?, ?, ?, ?)
        """, (title, price, rating, link))

        # Optional: commit once per item (fine for small projects)
        self.conn.commit()

        return item






import scrapy

class BookstoscrapeItem(scrapy.Item):
    # Define the fields for your item
    link = scrapy.Field()
    title = scrapy.Field()
    price = scrapy.Field()
    rating = scrapy.Field()
    
