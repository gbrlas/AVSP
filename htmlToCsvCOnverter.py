from bs4 import BeautifulSoup
import csv
import urllib

name = 'file.html'
html = urllib.urlopen(name).read()        
soup = BeautifulSoup(html)
table = soup.find(lambda tag: tag.name=='table') 

with open("out.csv", "w") as f:
    wr = csv.writer(f)
    output = []
    rows = [[td.text.encode("utf-8") for td in row.find_all("td")] for row in table.select("tr + tr")]
    
    output.append(name)
    for r in rows:
    	output.append(r[2])

    wr.writerows([output])