import requests
from bs4 import BeautifulSoup
import csv

def scrape_quotes(url):
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')

    quotes_data = []
    quotes = soup.find_all("div", class_="quote")

    for quote in quotes:
        text = quote.find("span", class_="text").text
        author = quote.find("small", class_="author").text
        tags = [tag.text for tag in quote.find_all("a", class_="tag")]

        quotes_data.append({
            "Quote": text,
            "Author": author,
            "Tags": ", ".join(tags)
        })

    return quotes_data

def save_to_csv(data, filename='quotes.csv'):
    with open(filename, 'w', newline='', encoding='utf-8') as f:
        writer = csv.DictWriter(f, fieldnames=["Quote", "Author", "Tags"])
        writer.writeheader()
        writer.writerows(data)

if __name__ == "__main__":
    url = "http://quotes.toscrape.com/"
    quotes = scrape_quotes(url)
    save_to_csv(quotes)
    print(f"{len(quotes)} quotes saved to 'quotes.csv'.")
