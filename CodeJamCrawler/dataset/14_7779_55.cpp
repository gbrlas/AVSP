def magic(cards1, cards2):
    array = []
    for card in cards1:
        if card in cards2:
            array.append(card)
    if len(array) == 0:
        msg = "Volunteer cheated!"
    elif len(array) == 1:
        msg = array[0]
    else:
        msg ="Bad magician!"
    return msg

def main():
    f1 = open('input.txt', 'r')
    f2 = open('output.txt', 'w')
    N = int(f1.readline().rstrip())
    for i in range(N):
        row1 = int(f1.readline().rstrip())
        array1 = []
        for j in range(4):
            array1.append(map(int, f1.readline().rstrip().split()))
        cards1 = array1[row1-1]
        row2 = int(f1.readline().rstrip())
        array2 = []
        for k in range(4):
            array2.append(map(int, f1.readline().rstrip().split()))
        cards2 = array2[row2-1]
        msg = magic(cards1, cards2)
        f2.write("Case #" + str(i+1) + ": " + str(msg) + "\n")

main()
