# Import requests and BeautifulSoup libraries
import requests
from bs4 import BeautifulSoup

# Define the URL of the website
url = "https://apps.cra-arc.gc.ca/ebci/hacc/srch/pub/t3010/v25/t3010QlfdDns_dsplyovrvw"

# Send a GET request to the website and store the response
response = requests.get(url)

# Check if the response status code is 200 (OK)
if response.status_code == 200:
    # Parse the response content using BeautifulSoup
    soup = BeautifulSoup(response.content, "html.parser")
    print(soup)
    # Find the table element that contains the data
    table = soup.find("table", id="t3010QlfdDns")

    # Find all the table rows (tr) elements in the table
    rows = table.find_all("tr")

    # Loop through the rows, skipping the first one (header)
    for row in rows[1:]:
        # Find all the table data (td) elements in the row
        data = row.find_all("td")

        # Extract the name, business number, and amount of gifts from the data
        name = data[0].text.strip()
        business_number = data[1].text.strip()
        amount = data[2].text.strip()

        # Print the data in a comma-separated format
        print(f"{name},{business_number},{amount}")
else:
    # Print an error message if the response status code is not 200
    print(f"Error: Could not access the website. Status code: {response.status_code}")
