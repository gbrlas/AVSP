def main():
    fin = open("A-small-attempt0.in.txt", "r")
    fout = open("A-small-attempt0.out.txt", "w")
    lines = int((fin.readline())[:-1])

    for i in range(lines):
        choice1 = int((fin.readline())[:-1])

        arr1 = []
        for j in range(4):
            temp = (fin.readline())[:-1]
            if (j + 1) == choice1:
                arr1 = temp.split()

        choice2 = int((fin.readline())[:-1])

        arr2 = []
        for j in range(4):
            temp = (fin.readline())[:-1]
            if (j + 1) == choice2:
                arr2 = temp.split()

        equal = ""
        equal_count = 0

        for j in arr1:
            for k in arr2:
                if j == k:
                    equal = j
                    equal_count += 1

        if equal_count == 0:
            fout.write("Case #" + str(i + 1) + ": Volunteer Cheated!\n")
        elif equal_count == 1:
            fout.write("Case #" + str(i + 1) + ": " + equal + "\n")
        else:
            fout.write("Case #" + str(i + 1) + ": Bad magician!\n")

    fin.close()
    fout.close()

main()
