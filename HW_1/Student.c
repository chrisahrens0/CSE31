#define MAX_NAME_LEN 128

typedef struct {
    char name[MAX_NAME_LEN];
    unsigned long sid;
} Student;

const char* getName(const Student* s) {
    return s->name;
}

void setName(Student* s, const char* name) {
    for(int i = 0; i <= sizeof(name); i++){
        (s->name[i] = name[i]);
    }
}

unsigned long getStudentID(const Student* s) {
    return s->sid;
}

void setStudentID(Student* s, unsigned long sid) {
    s->sid = sid;
}

