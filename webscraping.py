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

class BooksSpider(scrapy.Spider):
    name = "books"
    allowed_domains = ["books.toscrape.com"]
    start_urls = ["http://books.toscrape.com/"]

    def parse(self, response):
        # Select all book containers
        books = response.xpath('//article[@class="product_pod"]')

        for book in books:
            title = book.xpath('.//h3/a/@title').get()
            price = book.xpath('.//p[@class="price_color"]/text()').get()
            rating = book.xpath('.//p[contains(@class,"star-rating")]/@class').get().split()[-1]
            link = book.xpath('.//h3/a/@href').get()
            full_link = response.urljoin(link)

            yield scrapy.Request(
                full_link,
                callback=self.parse_book_page,
                meta={'title': title, 'price': price, 'rating': rating, 'link': full_link}
            )

        # Pagination
        next_page = response.xpath('//li[@class="next"]/a/@href').get()
        if next_page:
            yield response.follow(next_page, callback=self.parse)

    def parse_book_page(self, response):
        title = response.meta['title']
        price = response.meta['price']
        rating = response.meta['rating']
        link = response.meta['link']

        desc = response.xpath('normalize-space(//div[@id="product_description"]/following-sibling::p/text())').get()
        availability = response.xpath('normalize-space(//p[contains(@class,"instock")])').get()

        yield {
            'Title': title,
            'Price': price,
            'Rating': rating,
            'Link': link,
            'Description': desc if desc else "N/A",
            'Availability': availability if availability else "N/A"
        }







import sqlite3
import csv
import json

class CSVWriterPipeline:
    def open_spider(self, spider):
        self.file = open('books.csv', 'w', newline='', encoding='utf-8')
        self.writer = None

    def process_item(self, item, spider):
        if self.writer is None:
            self.writer = csv.DictWriter(self.file, fieldnames=item.keys())
            self.writer.writeheader()
        self.writer.writerow(item)
        return item

    def close_spider(self, spider):
        self.file.close()


import json

class JsonWriterPipeline:
    def open_spider(self, spider):
        self.file = open('books.json', 'w', encoding='utf-8')
        self.file.write('[')  # start of list
        self.first_item = True

    def close_spider(self, spider):
        self.file.write(']')
        self.file.close()

    def process_item(self, item, spider):
        if not self.first_item:
            self.file.write(',')
        else:
            self.first_item = False
        line = json.dumps(dict(item), ensure_ascii=False)
        self.file.write('\n' + line)
        self.file.flush()  # ensures partial data is written
        return item


class DatabasePipeline:
    def open_spider(self, spider):
        # Connect to SQLite (you can replace with MySQL if needed)
        self.connection = sqlite3.connect('books.db')
        self.cursor = self.connection.cursor()
        self.cursor.execute('''
            CREATE TABLE IF NOT EXISTS books (
                title TEXT,
                price TEXT,
                rating TEXT,
                link TEXT,
                description TEXT,
                availability TEXT
            )
        ''')
        self.connection.commit()

    def process_item(self, item, spider):
        self.cursor.execute('''
            INSERT INTO books (title, price, rating, link, description, availability)
            VALUES (?, ?, ?, ?, ?, ?)
        ''', (
            item.get('Title'),
            item.get('Price'),
            item.get('Rating'),
            item.get('Link'),
            item.get('Description'),
            item.get('Availability')
        ))
        self.connection.commit()
        return item

    def close_spider(self, spider):
        self.connection.close()






ITEM_PIPELINES = {
    'bookstoscrape.pipelines.CSVWriterPipeline': 300,
    'bookstoscrape.pipelines.JsonWriterPipeline': 400,
    'bookstoscrape.pipelines.DatabasePipeline': 500,
}





    
