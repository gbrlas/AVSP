class tokenizer{
private:
    FILE* dataFile;
    char line[1024];
    char* retval;
    char MOD_SEPS[32];
    void setFile(FILE* fp);
public:
    tokenizer();
    tokenizer(FILE* fp);
    void setSEPS(const char*);
    char* getToken();
    ~tokenizer();
};