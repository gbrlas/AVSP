def main():
   f = open("A-small-attempt0.in.txt", 'r')
   outfile = open("out", 'w') 
   test_cases = int(f.readline())
   print(test_cases)
   for i in range(0, test_cases):
      answer1 = int(f.readline())-1
      cards = []
      for j in range(0, 4):
         line = f.readline()
         s = line.split()
         row = [int(s[0]), int(s[1]), int(s[2]), int(s[3])]
         cards.append(row)
      possible = cards[answer1]
      print("answer1 = " + str(answer1))
      print(possible)
      answer2 = int(f.readline())-1
      cards2 = []
      for j in range(0, 4):
         line = f.readline()
         s = line.split()
         row = [int(s[0]), int(s[1]), int(s[2]), int(s[3])]
         cards2.append(row)
      possible2 = cards2[answer2]
      print("answer2 = " + str(answer2))
      print(possible2)
      final = []
      for n in possible:
         for m in possible2:
            if n == m:
               final.append(n)
      print("final = " + str(final))
      if len(final) == 0:
         print("length = 0")
         outfile.write("Case #" + str(i+1) + ": Volunteer cheated!\n")
      elif len(final) == 1:
         print("length = 1")
         print("Case #{}: {}".format(i+1, final[0]))
         outfile.write("Case #" + str(i+1) + ": " + str(final[0])+ "\n")
      else:
         print("length > 1")
         outfile.write("Case #" + str(i+1) + ": Bad magician!\n")

if __name__ == "__main__":
   main()
