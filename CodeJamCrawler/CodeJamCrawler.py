from bs4 import BeautifulSoup
import zipfile
import os

import urllib
#import urllib.urlretrieve

parser = 'html.parser'
id_counter=0

def process_body(soup):
    #print soup.body
    #print dir(soup)
    body = BeautifulSoup(str(soup.body), 'html.parser')
    content = BeautifulSoup(str(body.find_all('div', id='content')[0]), 'html.parser')
    # get display block
    display = BeautifulSoup(str(content.find_all('div')[1]), 'html.parser')
    table = BeautifulSoup(str(display.find_all('table', class_='stats')[0]), 'html.parser')
    round = BeautifulSoup(str(table.find('caption')), 'html.parser')
    score = BeautifulSoup(str(round.find('span')), 'html.parser').string.split(' ')[0]
    table_body = table.findAll('tr')
    #for row in table_body:
     #   print row
    print score
    code_links = table_body[2].find_all('a')
    for link in code_links:
        print link.get('href')
        global id_counter
        path_to_zip = 'dataset/' + str(id_counter) + '_' + score + '.zip'
        urllib.urlretrieve(link.get('href'), path_to_zip)
        #print path_to_file
        zip_ref = zipfile.ZipFile(path_to_zip, 'r')
        for file_name in zip_ref.namelist():
            path_to_file = 'dataset/' + str(id_counter) + '_' + score + '.cpp'
            output = open(path_to_file, 'w')
            id_counter += 1
            output.write(zip_ref.read(file_name))
        zip_ref.close()

        os.remove(path_to_zip)

        #id_counter += 1

def process_contestant(url):
    page = urllib.urlopen(url).read()
    soup = BeautifulSoup(page, 'html.parser')
    process_body(soup)

def main():
    with open('users.txt', 'r') as file:
        lines = file.readlines()

        for i in range(0, len(lines)):
            for year in ["08", "09", "10", "11", "12", "13", "14"]:
                print lines[i]
                url = "https://www.go-hero.net/jam/" + year + "/name/" + lines[i]
                try:
                    process_contestant(url)
                except IndexError as e:
                    print "Hadn't done shit this year. Sucked on mamas tities!"
                    continue

if __name__ == '__main__':
    main()