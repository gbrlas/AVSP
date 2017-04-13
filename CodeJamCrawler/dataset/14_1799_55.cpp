def main():
    fin = open("B-small-attempt0.in.txt", "r")
    fout = open("B-small-attempt0.out.txt", "w")
    lines = int((fin.readline())[:-1])

    for i in range(lines):
        line = (fin.readline())[:-1].split()
        c, f, x = float(line[0]), float(line[1]), float(line[2])

        time = 0.0
        rate = 2.0
        while ((c / rate) + (x / (rate + f))) < (x / rate):
            time += (c / rate)
            rate += f
        time += (x / rate)

        fout.write("Case #" + str(i + 1) + ": " + str(time) + "\n")

    fin.close()
    fout.close()

main()
