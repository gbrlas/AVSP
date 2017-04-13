# This Python file uses the following encoding: utf8
import sys
import re


def inputParser(filename):
  text = open(filename).read().splitlines()
  text.pop(0)
  return text


def replaceLetters(instr):
  dict = {"a": "y",
          "b": "h",
          "c": "e",
          "d": "s",
          "e": "o",
          "f": "c",
          "g": "v",
          "h": "x",
          "i": "d",
          "j": "u",
          "k": "i",
          "l": "g",
          "m": "l",
          "n": "b",
          "o": "k",
          "p": "r",
          "q": "z",  # NOT SURE
          "r": "t",
          "s": "n",
          "t": "w",
          "u": "j",
          "v": "p",
          "w": "f",
          "x": "m",
          "y": "a",
          "z": "q"}  # NOT SURE
  inlist = list(instr)
  outlist = []
  for char in list(instr):
    if char not in dict:
      outlist.append(char)
    else:
      outlist.append(dict[char.lower()])
  return "".join(outlist)


def outtextGen(lines):
  outtext = ""
  i = 1
  for line in lines:
    outtext += "Case #%s: %s\n" %(i, line)
    i += 1
  return outtext


def outputWriter(filename,outtext):
  outfile = open(filename, 'w')
  outfile.write(outtext)


def main():
  if len(sys.argv) != 3:
    print 'usage: ./alphabetSoup.py file-to-read file-to-write'
    sys.exit(1)
  
  lines = [replaceLetters(line) for line in inputParser(sys.argv[1])]
  outtext = outtextGen(lines)
  outputWriter(sys.argv[2],outtext)

if __name__ == '__main__':
  main()