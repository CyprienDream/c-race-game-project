#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sortedlist.h"
#include "LS_allegro.h"
#include "view/ViewComponent.h"
#include "view/BoxBoundViewComponent.h"
#include "view/BitMapViewComponent.h"
#include "string.h"
#include "view/CarBoxComponent.h"

#define STRING_LENGTH 500
#define MAX_DRIVERS 7

typedef struct {
    char array[STRING_LENGTH];
    int length;
}String;

struct DriverInfo{
    char *name;
    int driver_number;
    char *team_name;
    int reflexes;
    int phys_cond;
    int temperament;
    int tyre;
    int op1_done;
};

struct Part{
    String name;
    int speed;
    int acceleration;
    int consumption;
    int reliability;
};

struct Category{
    String name;
    int num_parts;
    struct Part *parts;
};

struct Racer{
    char name[25];
    int driver_number;
    char team_name[25];
    int speed;
    int acceleration;
    int consumption;
    int reliability;
    int reflexes;
    int phy_condition;
    int temperament;
    int tyre_management;
};

struct CarStats{
    int speed;
    int acceleration;
    int consumption;
    int reliability;
};

typedef struct {
    struct DriverInfo my_driver;
    struct Racer *racers;
    struct Category *categories;
    struct CarStats stats;
    SortedList *list;
    int num_cat;
    int num_GPs;
    int files_ok;
}Model;

String setString (char input[]){
    String output = {'\0', 0};
    int i;

    for (i = 0; i <= strlen(input); i++){
        output.array[i] = input[i];
    }
    output.length = i - 1;
    return output;
}

void *initializeCharArray(char *array){
    int i;

    for(i=0; i<strlen(array); i++){
        array[i] = '\0';
    }
}

struct DriverInfo initializeDriverInfo (){
    struct DriverInfo d;

    d.driver_number = 0;
    d.phys_cond = 0;
    d.reflexes = 0;
    d.temperament = 0;
    d.tyre = 0;
    d.op1_done = 0;
    return d;
}

struct Racer initializeRacer(){
    struct Racer racer;

    racer.driver_number = 0;
    racer.speed = 0;
    racer.acceleration = 0;
    racer.consumption = 0;
    racer.reliability = 0;
    racer.reflexes = 0;
    racer.phy_condition = 0;
    racer.temperament = 0;
    racer.tyre_management = 0;

    return racer;
}

Model *initializeModel(){
    Model *m = (Model*)malloc(sizeof(Model));

    m->my_driver = initializeDriverInfo();

    m->num_cat = 0;
    m->num_GPs = 0;
    m->files_ok = 1;

    return m;
}

int stringToInt(String input){
    int i, offset = 0, n = 0;

    if(input.array[0] == '-') offset = 1;

    for (i = offset; input.array[i] != '\n' && input.array[i] != '\0'; i++){
        n = n * 10 + input.array[i] - '0';
    }
    if (offset == 1) n *= -1;

    return n;
}

String getString (){
    String string;
    char input[STRING_LENGTH];
    fgets(input, STRING_LENGTH, stdin);
    string = setString(input);
    string.array[string.length] = '\0';
    string.length++;
    return string;
}

int error_optionInput(int input){
    if (input < 1 || input > 4){
        return 1;
    } else {
        return 0;
    }
}

static int isExit(String input){
    if(strcmp(input.array, "exit\n") == 0){
        return 1;
    } else {
        return 0;
    }
}

int getOption (String input){
    int option = 0;

    option = stringToInt(input);
    if (error_optionInput(option) && !isExit(input)) {
        printf("\nERROR: option is not valid\n");
    }
    return option;
}

void printMenu (){
    printf("\n\t1. Configure car\n"
           "\t2. Race\n"
           "\t3. See standings\n"
           "\t4. Save season\n"
           "\nWhat option do you want to execute? ");
}

//OPTION 1

int isStringLongerThan25(char *input){
    return (strlen(input) > 26) ? 1 : 0;
}

int error_DriverNumber(int input){
    if(input < 1 || input > 99){
        printf("Error, the number has to be an integer between 1 and 99.\n");
        return 1;
    } else {
        return 0;
    }
}

int isIntegerNotBetween0And10(int input, char *type){
    if (input < 0 || input > 10){
        printf("Error, the %s has to be between 0 and 10, both inclusive.\n", type);
        return 1;
    } else {
        return 0;
    }
}

char *getName (char *type){
    char *input = (char*)malloc(sizeof(char)*STRING_LENGTH);
    int error = 0;

    do {
        printf("%s? ", type);
        fgets(input, STRING_LENGTH, stdin);
        if (isStringLongerThan25(input)) {
            printf("Error, name is longer than 25 characters.\n");
            error = 1;
        }
    } while(error);
    return input;
}

int getInteger (){
    String input = setString("");
    int output;

    input = getString();
    output =stringToInt(input);
    return output;
}

int getDriverNumber (){
    int num;
    do{
        printf("Driver number?");
        num = getInteger();
    } while(error_DriverNumber(num));
    return num;
}

int getDriverReflexes(){
    int num;
    do{
        printf("Reflexes? ");
        num = getInteger();
    } while(isIntegerNotBetween0And10(num, "reflex number"));
    return num;
}

int getDriverPhysicalCondition(){
    int num;
    do{
        printf("Physical condition? ");
        num = getInteger();
    } while(isIntegerNotBetween0And10(num, "physical condition number"));
    return num;
}

int getDriverTemperament(){
    int num;
    do{
        printf("Temperament? ");
        num = getInteger();
    } while(isIntegerNotBetween0And10(num, "temperament number"));
    return num;
}

int getDriverTyreManagement(){
    int num;
    do{
        printf("Tyre management? ");
        num = getInteger();
    } while(isIntegerNotBetween0And10(num, "tyre management number"));
    return num;
}

struct DriverInfo getDriverInfo(){
    struct DriverInfo d = initializeDriverInfo();

    d.name = getName("Driver name");
    d.team_name = getName("Team name");
    d.driver_number = getDriverNumber();
    d.reflexes = getDriverReflexes();
    d.phys_cond = getDriverPhysicalCondition();
    d.temperament = getDriverTemperament();
    d.tyre = getDriverTyreManagement();
    d.op1_done = 1;

    return d;
}

struct DriverInfo optionOne (struct DriverInfo d){
    if(d.op1_done == 0) {
        d = getDriverInfo();
    }
    printf("Loading configurator ...\n");

    //
    return d;
}

Model *manageOptions (int option, Model *m){

    switch (option){
        case 1:
            m->my_driver = optionOne(m->my_driver);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        default:

            break;
    }
    return m;
}

void fileErrorManager (int type){
    static int error = 0;
    if (error != 10) {
        if (type == 1) {
            printf("Error, file does not exist.\n");
            error = 10;
        }
        if (type == 2) {
            printf("Error, file is empty.\n");
            error = 10;
        }
    }
}

Model *processBaseFile (char *file_name, Model *m){
    FILE *fp = NULL;
    int i;

    fp = fopen(file_name, "rb");

    if(fp == NULL) {
        fileErrorManager(1);
        m->files_ok = 0;
    } else {
        fseek(fp, 0, SEEK_END);
        if (!ftell(fp)) {
            fileErrorManager(2);
            m->files_ok = 0;
        } else {
            fseek(fp, 0, SEEK_SET);
            fread(&m->stats, sizeof(struct CarStats), 1, fp);
        }
        fclose(fp);
    }

    return m;
}

Model *processRacersFile (char *file_name, Model *m){
    FILE *fp = NULL;
    int i;

    m->racers = (struct Racer*)malloc(sizeof(struct Racer));

    fp = fopen(file_name, "rb");

    if(fp == NULL) {
        fileErrorManager(1);
        m->files_ok = 0;
    } else {
        fseek(fp, 0, SEEK_END);
        if (!ftell(fp)) {
            fileErrorManager(2);
            m->files_ok = 0;
        } else {
            fseek(fp, 0, SEEK_SET);
            m->racers = realloc(m->racers, sizeof(struct Racer)*MAX_DRIVERS);
            for(i = 0; i < MAX_DRIVERS; i++){
                m->racers[i] = initializeRacer();
                fread(&m->racers[i], sizeof(struct Racer), 1, fp);
            }
        }
        fclose(fp);
    }
    return m;
}

Model *processGPsFile (char *file_name, Model *m){
    int i;
    FILE *fp = NULL;
    m->list = (SortedList*)malloc(sizeof(SortedList));
    *m->list = SORTEDLIST_create();
    Element e;

    fp = fopen(file_name, "r");

    if(fp == NULL) {
        fileErrorManager(1);
        m->files_ok = 0;
    } else {
        fseek(fp, 0, SEEK_END);
        if (!ftell(fp)) {
            fileErrorManager(2);
            m->files_ok = 0;
        } else {
            fseek(fp, 0, SEEK_SET);
            fscanf(fp, "%d", &m->num_GPs);

            for (i = 0; i < m->num_GPs; i++){

                fscanf(fp, "%d", &e.circuit_number);
                fscanf(fp, " %[^\n]", e.name);
                fscanf(fp, "%d", &e.speed);
                fscanf(fp, "%d", &e.acceleration);
                fscanf(fp, "%d", &e.consumption);
                fscanf(fp, "%d", &e.reliability);
                fscanf(fp, "%f", &e.time);
                fscanf(fp, "%d", &e.pit_stop_time);
                fscanf(fp, "%d", &e.num_pit_stop);
                SORTEDLIST_sortedAdd(m->list, e);
            }
        }
        fclose(fp);
    }
    return m;
}

Model *processPartsFile (char *file_name, Model *m){
    FILE *fp = NULL;
    int i, j;


    fp = fopen(file_name, "r");

    if(fp == NULL) {
        fileErrorManager(1);
        m->files_ok = 0;
    } else {
        fseek(fp, 0, SEEK_END);
        if (!ftell(fp)) {
            fileErrorManager(2);
            m->files_ok = 0;
        } else {
            fseek(fp, 0, SEEK_SET);
            fscanf(fp, "%d", &m->num_cat);
            m->categories = malloc(m->num_cat * sizeof(struct Category));

            for (i = 0; i < m->num_cat; i++) {
                fscanf(fp, " %[^\n]", m->categories[i].name.array);
                fscanf(fp, "%d", &m->categories[i].num_parts);
                m->categories[i].parts = (struct Part *) malloc(sizeof(struct Part) * m->categories[i].num_parts);

                for (j = 0; j < m->categories[i].num_parts; j++) {
                    fscanf(fp, " %[^\n]", m->categories[i].parts[j].name.array);
                    fscanf(fp, "%d", &m->categories[i].parts[j].speed);
                    fscanf(fp, "%d", &m->categories[i].parts[j].acceleration);
                    fscanf(fp, "%d", &m->categories[i].parts[j].consumption);
                    fscanf(fp, "%d", &m->categories[i].parts[j].reliability);
                }
            }
        }
        fclose(fp);
    }
    return m;
}

Model *processFiles (char **argv, Model *m){

    m = processPartsFile (argv[1], m);
    m = processGPsFile(argv[2], m);
    m = processRacersFile(argv[3], m);
    m = processBaseFile(argv[4], m);

    return m;
}

int checkNumArguments (int argc){
    return (argc == 5);
}

int canProgramStart (int argc){
    if(checkNumArguments(argc)){
        return 1;
    } else {
        printf("Error, the program should have 4 arguments.\n");
        return 0;
    }
}

void test() {
    LS_allegro_init(1200, 600, "CUNT");
    char* wd = malloc(1000*sizeof(char));
    ViewComponent* viewComponent1 = (ViewComponent*) BOX_BOUND_VIEW_COMPONENT_createDefault(200, 200, 0, GREEN, 400, 410);
    ViewComponent* viewComponent = CAR_BOX_COMPONENT_constructor(strcat(getcwd(wd, 1000), "/boxes.png"), 1200, 600);

    VIEW_COMPONENT_addChild(viewComponent1, viewComponent);
    while(true) {
        VIEW_COMPONENT_draw(viewComponent1);
        LS_allegro_clear_and_paint(BLACK);

    }

    LS_allegro_exit();
}

int main(int argc, char **argv) {
    String input = setString("");
    int option = 0;
    Model *m = initializeModel();

    test();
    if (canProgramStart(argc)) {
        m = processFiles(argv, m);
        if (m->files_ok) {
            printf("Welcome to LS Racing!\n");
            do {
                printMenu();
                input = getString();
                option = getOption(input);
                m = manageOptions(option, m);
            } while (!isExit(input));
            printf("\nSee you soon!");
        }
    }

    return 0;
}