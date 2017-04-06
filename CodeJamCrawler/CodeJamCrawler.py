from bs4 import BeautifulSoup
import zipfile
import os
import time
import threading

import urllib

parser = 'html.parser'
id_counter=0

def process_body(soup, year):
    body = BeautifulSoup(str(soup.body), 'html.parser')
    content = BeautifulSoup(str(body.find_all('div', id='content')[0]), 'html.parser')
    # get display block
    display = BeautifulSoup(str(content.find_all('div')[1]), 'html.parser')
    tables = display.find_all('table', class_='stats')
    for tab in tables:
        table = BeautifulSoup(str(tab), 'html.parser')
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
            zip_ref = zipfile.ZipFile(path_to_zip, 'r')
            #print path_to_file
            for file_name in zip_ref.namelist():
                path_to_file = 'dataset/' + year + '_' + str(id_counter) + '_' + score + '.cpp'
                output = open(path_to_file, 'w')
                id_counter += 1
                output.write(zip_ref.read(file_name))
            zip_ref.close()

            os.remove(path_to_zip)
        time.sleep(0.1)

def process_contestant(url, year):
    page = urllib.urlopen(url).read()
    soup = BeautifulSoup(page, 'html.parser')
    process_body(soup, year)

def process_contest(year, lines):
    for i in range(0, len(lines)):
        print lines[i]
        url = "https://www.go-hero.net/jam/" + year + "/name/" + lines[i]
        try:
            process_contestant(url, year)
        except IndexError as e:
            continue

def main():
    print os.getcwd()
    with open('users.txt', 'r') as file:
        lines = file.readlines()

        threads = []

        years = ["08", "09", "10", "11", "12", "13", "14"]
        for year in years:
            t = threading.Thread(target=process_contest, args=(year, lines))
            t.start()
            threads.append(t)
            print "created thread for year", year
            #process_contest(year, lines)

        for index in range(len(threads)):
            threads[index].join()

if __name__ == '__main__':
    main()