#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
    const char *map = "yhesocvxduiglbkrztnwjpfmaq";
    int cases = 0;
    std::ifstream in(argv[1]);
    std::ofstream out(argv[2]);
    in >> cases;
    std::string line;
    std::getline(in,line);
    for (int i = 1; i <= cases; i++) {
        std::getline(in, line);
        out << "Case #" << i << ": ";
        for (int j = 0; j < line.length(); j++) {
            if (line[j] == ' ') {
                out << ' ';
            } else {
                out << map[line[j]-'a'];
            }
        }
        out << std::endl;
    }
    return 0;
}
