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
