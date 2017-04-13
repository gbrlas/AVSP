import copy

__author__ = 'basit'

file_input = open("repeater.in")
file_output = open("repeater.out", "w")


def read_int_array():
    inputs = file_input.readline().split()
    return [int(x) for x in inputs]


def trim_string(in_string=""):
    out_string = str(in_string)
    alphabets = set(list(in_string))
    for alpha in alphabets:
        to_replace = "%s%s" % (alpha, alpha)
        while to_replace in out_string:
            out_string = out_string.replace(to_replace, alpha)

    return out_string


def alpha_counts(in_string=""):
    counts = []

    current_alpha = -1
    current_count = 0
    for char in in_string:
        if char == current_alpha:
            current_count += 1
        else:
            if current_alpha != -1:
                counts.append(current_count)

            current_alpha = char
            current_count = 1

    counts.append(current_count)
    return counts


def number_of_moves(string1, string2, target_counts):
    string_counts = alpha_counts(string2)
    if len(string_counts) != len(target_counts):
        print string1
        print string2
        print(string_counts)
        print(target_counts)

    moves = 0
    for x in xrange(len(string_counts)):
        moves += abs(target_counts[x] - string_counts[x])

    return moves


def main():
    # initialization input
    num_of_cases = int(file_input.readline())

    for case in xrange(num_of_cases):
        number_of_strings = int(file_input.readline())
        strings = [file_input.readline().strip() for x in xrange(number_of_strings)]

        if case > 0:
            file_output.write("\n")

        base_string = trim_string(strings[0])
        base_string_length = len(base_string)
        lost = False
        for string in strings:
            if trim_string(string) != base_string:
                lost = True

        if not lost:
            moves = 0
            for string in strings:
                moves += abs(base_string_length - len(string))

            for target_string in strings:
                new_move = 0
                target_counts = alpha_counts(target_string)
                for string in strings:
                    new_move += number_of_moves(target_string, string, target_counts)

                if new_move < moves:
                    moves = new_move

        if lost:
            result = "Case #%d: %s" % (case + 1, "Fegla Won")
        else:
            result = "Case #%d: %d" % (case + 1, moves)

        print result
        file_output.write(result)

    file_output.close()


if __name__ == '__main__':
    main()