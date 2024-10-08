#include <iostream>

#include <windows.h> //cursor
#include <sstream> // gennumeros ostringstream
#include <iomanip> // gen numer setfill  setw y listar con setw
#include <cctype> // Incluye la biblioteca cctype para detectar vars M-m-n
#include <string> // para var cadenas
#include <map> //DB
#include <regex> //formatos de escritura

using namespace std;

void dogs_menu();
void cats_menu();

// Función para posicionar el cursor correctamente antes de dibujar cada parte del cuadro.
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para posicionar el cursor correctamente antes de dibujar cada parte del cuadro.
void print_lines(int x1, int y1, int x2, int y2) {
    // Dibujar las líneas horizontales
    for (int x = x1; x <= x2; x++) {
        gotoxy(x, y1);
        cout << "-";
        gotoxy(x, y2);
        cout << "-";
    }

    // Dibujar las líneas verticales
    for (int y = y1; y <= y2; y++) {
        gotoxy(x1, y);
        cout << "|";
        gotoxy(x2, y);
        cout << "|";
    }

    // Dibujar las esquinas
    gotoxy(x1, y1);
    cout << "+";
    gotoxy(x2, y1);
    cout << "+";
    gotoxy(x1, y2);
    cout << "+";
    gotoxy(x2, y2);
    cout << "+";
}

// Colocar el cursor en la posición necesaria
void SetCursorPosition(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para poner texto dentro del cuadro
void print_text(int x, int y, const string& texto) {
    gotoxy(x, y);
    cout << texto;
}

bool check_val(string var_char, int var_for, int var_to){
    bool check;
    if (isalpha(var_char[0])){ // verificar si es letra
        check = true;
    }
    else{
        if (var_char.length() == 1 && isdigit(var_char[0])){ // Verificar si var_char es un solo dígito
            int convert = stoi(var_char); // Convertir var_char a un número entero  
            if (convert >= var_for && convert <= var_to){
                check = false;
            }
            else{
                check = true;
            }
        }
        else{
            check = true;
        }
    }
    return check;
}

int convert_to_int(string var_char){
    int convert = stoi(var_char); // Convertir var_char a un número entero  
    // cout << convert;
    return convert;
}

string read_string(){
    string val_char;
    cin >> val_char;
    return val_char;
}

int close_program(){
    ExitProcess(0);
    return 0;
}

void clean_screen(){
    system("cls");
}

void paint_table(){
    print_lines(0,0,119,2);//Cuadro del titulo
    print_lines(0,2,119,29);//Cuadro grande
    print_text(44, 1, "ALBERGUE DE PERROS Y GATOS");
}


bool valid_word(const string& nombre) {
    bool check;
    // Expresión regular para verificar si la cadena contiene solo letras y espacios
    regex exp("[a-zA-Z]+");

    // Verifica si la cadena coincide con la expresión regular
    // return regex_match(nombre, exp);
    if (regex_match(nombre, exp)){
        check = false;
    }
    else{
    check = true;
    }
    return check;
}

bool valid_si_no(const string& nombre) {
    if (nombre != "Si" && nombre != "No" && nombre != "si" && nombre != "no"){
        return true;
    }
    return false;
}

bool valid_raza(const string& nombre) {
    bool check;
    regex exp("^[a-zA-Z]+( [a-zA-Z]+)*$");
    if (regex_match(nombre, exp)){
        check = false;
    }
    else{
    check = true;
    }
    return check;
}

bool valid_number(const string& number) {
    bool check;
    if (isdigit(number[0])) {
        check = false;
    }
    else{
        check = true;
    }
    return check;
}

string convert_month(string age_animal){
    int convert = stoi(age_animal); // Convertir var_char a un número entero  
    int age = convert / 12;
    int month = convert % 12;

    string val_month;
    if (age >= 1) {
        val_month = to_string(age);
        val_month += "." + to_string(month);
    } else {
        val_month = "0." + to_string(convert);
    }

    return val_month;
}

bool valid_date(const string& fecha) {
    // Verificar si la cadena coincide con el formato dd/mm/yy usando una expresión regular
    regex formatoFecha("\\b\\d{2}/\\d{2}/\\d{2}\\b");
    if (!regex_match(fecha, formatoFecha)) {
        return true;
    }

    // Extraer día, mes y año de la cadena
    int dia, mes, ano;
    char separador1, separador2;
    istringstream iss(fecha);
    if (!(iss >> dia >> separador1 >> mes >> separador2 >> ano) || separador1 != '/' || separador2 != '/') {
        return true;
    }

    // Verificar los rangos de día, mes y año
    if (mes < 1 || mes > 12 || dia < 1 || dia > 31) {
        return true;
    }

    // Verificar los días máximos de cada mes
    int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Año bisiesto (el año es del formato yy, por lo tanto cualquier valor entre 00 y 99)
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
        diasPorMes[1] = 29;
    }

    if (dia > diasPorMes[mes - 1]) {
        return true;
    }

    return false;
}

bool valid_sex(const string& sexo){
    if (sexo != "Macho" && sexo != "macho" && sexo != "m" && sexo != "M" && sexo != "Hembra" && sexo != "hembra" && sexo != "h" && sexo != "H"){
        return true;
    }
    return false;
}

string convert_sex(const string& sex){
    string val_sex;
    if (sex == "Macho" || sex == "macho" || sex == "m" || sex == "M"){
        val_sex = "Macho";
    }
    else if (sex == "Hembra" || sex == "hembra" || sex == "h" || sex == "H"){
        val_sex = "Hembra";
    }
    return val_sex;
}

bool check_menu(const string& condition){
    if (condition != "Si" && condition != "si" && condition != "S" && condition != "s" && condition != "No" && condition != "no" && condition != "N" && condition != "n" ){
        return true;
    }
    return false;
}

struct Dog_database {
    string Name;
    string Raza;
    string Age;
    string Date;
    string Sex;
    string Adopt;
    string S_adop;
    string cm_out;
    string rv_healht;
    string vacuna;
};

map<string, Dog_database> db;

string generator_code_dogs(){
    string gen_code;
    for (int i = 1; i <= 999999; ++i) {
        // Convierte el número a una cadena con seis dígitos
        ostringstream ss;
        ss << setw(6) << setfill('0') << i;
        string numeroString = ss.str();
        // string numeroString = to_string(i);
        if (db.find(numeroString) == db.end()) {
            gen_code = numeroString;
            break; // Salir del bucle una vez que se encuentra un código en la base de datos
        }
    }
    return gen_code;
}

void ingresarDatos_dogs(
    string code,
    string Name,
    string Raza,
    string Age,
    string Date,
    string Sex) {

    string Adopt = "No";
    string S_adop = "No"; 
    string cm_out = "00/00/00";
    string rv_healht= "00/00/00";
    string vacuna = "Ninguna";
    
    // Guardamos los datos en la base de datos
    Dog_database new_dog = {Name,Raza,Age,Date,Sex,Adopt,S_adop,cm_out,rv_healht,vacuna};
    db[code] = new_dog;
}

// void mostrarDatos_perros() {
//     clean_screen();
//     paint_table();
//     print_text(49, 3, "LISTA DE PERROS");
//     print_lines(0,0,119,4);//Cuadro del titulo
//     cout << setw(8) << "Codigo"
//          << setw(15) << "Nombre"
//          << setw(20) << "Raza"
//          << setw(25) << "Edad"
//          << setw(30) << "Fecha de Ingreso"
//          << setw(17) << "Sexo" << endl;

//     for (auto& doggy : db) {
//         cout << setw(8) << doggy.first
//              << setw(15) << doggy.second.Name
//              << setw(20) << doggy.second.Raza
//              << setw(25) << doggy.second.Age
//              << setw(30) << doggy.second.Date
//              << setw(17) << doggy.second.Sex << endl;
//     }
// }

void mostrarDatos_perros() {
    clean_screen();
    paint_table();
    print_text(49, 3, "LISTA DE PERROS");
    print_lines(0,0,119,4);//Cuadro del titulo

    print_text(2, 5, "Codigo");
    print_text(20, 5, "Nombre");
    print_text(40, 5, "Raza");
    print_text(65, 5, "Edad");
    print_text(80, 5, "Fecha de Ingreso");
    print_text(108, 5, "Sexo");
    int lines = 7;
    for (auto& doggy : db) {
        print_text(2, lines, doggy.first);
        print_text(20, lines, doggy.second.Name);
        print_text(40, lines, doggy.second.Raza);
        print_text(65, lines, doggy.second.Age);
        print_text(80, lines, doggy.second.Date);
        print_text(108, lines, doggy.second.Sex);
        lines ++;
    }
}


struct Cat_database {
    string Name;
    string Raza;
    string Age;
    string Date;
    string Sex;
    string Adopt;
    string S_adop;
    string cm_out;
    string rv_healht;
    string vacuna;
};

map<string, Cat_database> dbase;

string generator_code_cats(){
    string random_code;
    for (int i = 1; i <= 999999; ++i) {
        // Convierte el número a una cadena con seis dígitos
        ostringstream stm;
        stm << setw(6) << setfill('0') << i;
        string s_number = stm.str();
        // string s_number = to_string(i);
        if (dbase.find(s_number) == dbase.end()) {
            random_code = s_number;
            break; // Salir del bucle una vez que se encuentra un código en la base de datos
        }
    }
    return random_code;
}

void ingresarDatos_cats(
    // Guardamos los datos en la base de datos
    string code,
    string Name,
    string Raza,
    string Age,
    string Date,
    string Sex) {

    string Adopt = "No";
    string S_adop = "No"; 
    string cm_out = "00/00/00";
    string rv_healht= "00/00/00";
    string vacuna = "Ninguna";
    
    // Guardamos los datos en la base de datos
    Cat_database new_cat = {Name,Raza,Age,Date,Sex,Adopt,S_adop,cm_out,rv_healht,vacuna};
    dbase[code] = new_cat;
}

void mostrarDatos_gatos() {
    clean_screen();
    paint_table();
    print_text(49, 3, "LISTA DE GATOS");
    print_lines(0,0,119,4);//Cuadro del titulo

    print_text(2, 5, "Codigo");
    print_text(20, 5, "Nombre");
    print_text(40, 5, "Raza");
    print_text(65, 5, "Edad");
    print_text(80, 5, "Fecha de Ingreso");
    print_text(108, 5, "Sexo");
    int lines = 7;
    for (auto& cat_mm : dbase) {
        print_text(2, lines, cat_mm.first);
        print_text(20, lines, cat_mm.second.Name);
        print_text(40, lines, cat_mm.second.Raza);
        print_text(65, lines, cat_mm.second.Age);
        print_text(80, lines, cat_mm.second.Date);
        print_text(108, lines, cat_mm.second.Sex);
        lines ++;
    }
}

bool back_menu_check(const string& letter){
    if (letter.empty()) {
        return true;
    }
    return false;
}

void change_dogs(const string& code, const string& type, const string& newValue) {
    auto info = db.find(code);
    if (info != db.end()) {
        if (type == "nombre") {
            info->second.Name = newValue;
        } else if (type == "raza") {
            info->second.Raza = newValue;
        } else if (type == "edad") {
            int age = convert_to_int(info->second.Age);
            int new_age = convert_to_int(newValue);
            if (new_age >> age) {
                info->second.Age = newValue;
            } else {
                print_text(5, 6, "Valor de edad no válido.");
            }
            info->second.Age = newValue;
        } else if (type == "fecha") {
            info->second.Date = newValue;
        } else if (type == "sexo") {
            info->second.Sex = newValue;
        } else if (type == "en_adopcion") {
            info->second.Adopt = newValue;
        } else if (type == "adoptado") {
            info->second.S_adop = newValue;
        } else if (type == "salida") {
            info->second.cm_out = newValue;
        } else if (type == "medica") {
            info->second.rv_healht = newValue;
        } else if (type == "vacuna") {
            info->second.vacuna = newValue;
        } else {
            print_text(5, 6, "\t\t Tipo de dato no válido.");
        }
    }
}

void dogs_inf(string code, const Dog_database& selec_dog) {
    string select_option, new_sssname,opts_tclaa;
    int k_optsm;
    clean_screen();
    paint_table();
    print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
    print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
    print_text(5, 8, "[3]Edad: "+selec_dog.Age);
    print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
    print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
    print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
    print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
    print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
    print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
    print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
    print_text(5, 16, "\tIngrese el numero que desea modificar o 11 para volver:");
    do
    {
        select_option = read_string();
        if (check_val(select_option,1,11)){
            clean_screen();
            paint_table();
            print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
            print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
            print_text(5, 8, "[3]Edad: "+selec_dog.Age);
            print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
            print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
            print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
            print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
            print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
            print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
            print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
            print_text(5, 16, "\tIngrese correctamente el numero:");
        }
    } while (check_val(select_option,1,11));

    k_optsm = convert_to_int(select_option);

    switch (k_optsm)
    {
    case 1:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
        print_text(5, 8, "[3]Edad: "+selec_dog.Age);
        print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
        print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
        print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
        print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
        print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
        print_text(5, 16, "\tIngrese el nuevo nombre del perro:");
        do
        {
            new_sssname = read_string();
            if (valid_word(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
                print_text(5, 8, "[3]Edad: "+selec_dog.Age);
                print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
                print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
                print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
                print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
                print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
                print_text(5, 16, "\tIngrese un nombre correcto:");
            }
        } while (valid_word(new_sssname));
        print_text(5, 17, "\tSe cambio "+selec_dog.Name+" por "+new_sssname);
        change_dogs(code, "nombre", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        dogs_menu();
        break;
    case 2:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
        print_text(5, 8, "[3]Edad: "+selec_dog.Age);
        print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
        print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
        print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
        print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
        print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
        print_text(5, 16, "\tIngrese la nueva raza del perro:");
        do
        {
            new_sssname = read_string();
            if (valid_raza(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
                print_text(5, 8, "[3]Edad: "+selec_dog.Age);
                print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
                print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
                print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
                print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
                print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
                print_text(5, 16, "\tIngrese la raza correctamenete:");
            }
        } while (valid_raza(new_sssname));
        print_text(5, 17, "\tSe cambio "+selec_dog.Raza+" por "+new_sssname);
        change_dogs(code, "raza", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        dogs_menu();
        break;
    case 3:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
        print_text(5, 8, "[3]Edad: "+selec_dog.Age);
        print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
        print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
        print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
        print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
        print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
        print_text(5, 16, "\tIngrese la nueva edad del perro:");
        do
        {
            new_sssname = read_string();
            if (valid_number(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
                print_text(5, 8, "[3]Edad: "+selec_dog.Age);
                print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
                print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
                print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
                print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
                print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
                print_text(5, 16, "\tIngrese una edad correcta:");
            }
        } while (valid_number(new_sssname));
        print_text(5, 17, "\tSe cambio "+selec_dog.Age+" por "+convert_month(new_sssname));
        change_dogs(code, "edad", convert_month(new_sssname));
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        dogs_menu();
        break;
    case 4:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
        print_text(5, 8, "[3]Edad: "+selec_dog.Age);
        print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
        print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
        print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
        print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
        print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
        print_text(5, 16, "\tIngrese la nueva fecha de ingreso del perro:");
        do
        {
            new_sssname = read_string();
            if (valid_date(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
                print_text(5, 8, "[3]Edad: "+selec_dog.Age);
                print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
                print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
                print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
                print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
                print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
                print_text(5, 16, "\tIngrese una fecha correcta:");
            }
        } while (valid_date(new_sssname));
        print_text(5, 17, "\tSe cambio "+selec_dog.Date+" por "+new_sssname);
        change_dogs(code, "fecha", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        dogs_menu();
        break;
    case 5:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
        print_text(5, 8, "[3]Edad: "+selec_dog.Age);
        print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
        print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
        print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
        print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
        print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
        print_text(5, 16, "\tIngrese el nuevo sexo del perro:");
        do
        {
            new_sssname = read_string();
            if (valid_sex(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
                print_text(5, 8, "[3]Edad: "+selec_dog.Age);
                print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
                print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
                print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
                print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
                print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
                print_text(5, 16, "\tIngrese un valor correcto:");
            }
        } while (valid_sex(new_sssname));
        print_text(5, 17, "\tSe cambio "+selec_dog.Sex+" por "+convert_sex(new_sssname));
        change_dogs(code, "sexo", convert_sex(new_sssname));
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        dogs_menu();
        break;
    case 6:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
        print_text(5, 8, "[3]Edad: "+selec_dog.Age);
        print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
        print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
        print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
        print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
        print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
        print_text(5, 16, "\tIngrese si esta en adopcion o no:");
        do
        {
            new_sssname = read_string();
            if (valid_si_no(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
                print_text(5, 8, "[3]Edad: "+selec_dog.Age);
                print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
                print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
                print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
                print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
                print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
                print_text(5, 16, "\tIngrese Solo si o no :");
            }
        } while (valid_si_no(new_sssname));
        print_text(5, 17, "\tSe cambio "+selec_dog.Adopt+" por "+new_sssname);
        change_dogs(code, "adopcion", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        dogs_menu();
        break;
    case 7:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
        print_text(5, 8, "[3]Edad: "+selec_dog.Age);
        print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
        print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
        print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
        print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
        print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
        print_text(5, 16, "\tIngrese Si o No (Adoptado):");
        do
        {
            new_sssname = read_string();
            if (valid_si_no(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
                print_text(5, 8, "[3]Edad: "+selec_dog.Age);
                print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
                print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
                print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
                print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
                print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
                print_text(5, 16, "\tIngrese si o no:");
            }
        } while (valid_si_no(new_sssname));
        print_text(5, 17, "\tSe cambio "+selec_dog.S_adop+" por "+new_sssname);
        change_dogs(code, "adoptado", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        dogs_menu();
        break;
    case 8:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
        print_text(5, 8, "[3]Edad: "+selec_dog.Age);
        print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
        print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
        print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
        print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
        print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
        print_text(5, 16, "\tIngrese la fecha de salida del albergue del perro:");
        do
        {
            new_sssname = read_string();
            if (valid_date(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
                print_text(5, 8, "[3]Edad: "+selec_dog.Age);
                print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
                print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
                print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
                print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
                print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
                print_text(5, 16, "\tFecha de salida cuando fue adoptado:");
            }
        } while (valid_date(new_sssname));
        print_text(5, 17, "\tSe cambio "+selec_dog.cm_out+" por "+new_sssname);
        change_dogs(code, "salida", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        dogs_menu();
        break;
    case 9:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
        print_text(5, 8, "[3]Edad: "+selec_dog.Age);
        print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
        print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
        print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
        print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
        print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
        print_text(5, 16, "\tIngrese la ultima fecha de revision medica del perro:");
        do
        {
            new_sssname = read_string();
            if (valid_date(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
                print_text(5, 8, "[3]Edad: "+selec_dog.Age);
                print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
                print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
                print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
                print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
                print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
                print_text(5, 16, "\tIngrese una fecha:");
            }
        } while (valid_date(new_sssname));
        print_text(5, 17, "\tSe cambio "+selec_dog.rv_healht+" por "+new_sssname);
        change_dogs(code, "medica", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        dogs_menu();
        break;
    case 10:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
        print_text(5, 8, "[3]Edad: "+selec_dog.Age);
        print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
        print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
        print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
        print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
        print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
        print_text(5, 16, "\tIngrese vacunas del perro:");
        do
        {
            new_sssname = read_string();
            if (valid_word(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+selec_dog.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+selec_dog.Raza);
                print_text(5, 8, "[3]Edad: "+selec_dog.Age);
                print_text(5, 9, "[4]Ingreso: "+selec_dog.Date);
                print_text(5, 10, "[5]Sexo: "+selec_dog.Sex);
                print_text(5, 11, "[6]En Adopcion: "+selec_dog.Adopt);
                print_text(5, 12, "[7]Adoptado: "+selec_dog.S_adop);
                print_text(5, 13, "[8]Salida: "+selec_dog.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+selec_dog.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+selec_dog.vacuna);
                print_text(5, 16, "\tIngrese nombre de la vacuna:");
            }
        } while (valid_word(new_sssname));
        print_text(5, 17, "\tSe cambio "+selec_dog.vacuna+" por "+new_sssname);
        change_dogs(code, "vacuna", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        dogs_menu();
    case 11:
        dogs_menu();
        break;
    }
}

void status_dogs(){
    string ing_dato;
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t Ingrese el codigo de un perro:");
    ing_dato = read_string();
    auto info = db.find(ing_dato);
    if (info != db.end()) {
        // Si se encuentra el animal, mostrar sus datos
        dogs_inf(ing_dato,info->second);
    } else {
        // Si no se encuentra el animal, mostrar un mensaje de error
        print_text(5, 6, "\t\t No se encontro los datos:");
    }
}

void change_cats(const string& code, const string& type, const string& newValue) {
    auto ll_d = dbase.find(code);
    if (ll_d != dbase.end()) {
        if (type == "nombre") {
            ll_d->second.Name = newValue;
        } else if (type == "raza") {
            ll_d->second.Raza = newValue;
        } else if (type == "edad") {
            int age = convert_to_int(ll_d->second.Age);
            int new_age = convert_to_int(newValue);
            if (new_age >> age) {
                ll_d->second.Age = newValue;
            } else {
                print_text(5, 6, "Valor de edad no válido.");
            }
            ll_d->second.Age = newValue;
        } else if (type == "fecha") {
            ll_d->second.Date = newValue;
        } else if (type == "sexo") {
            ll_d->second.Sex = newValue;
        } else if (type == "en_adopcion") {
            ll_d->second.Adopt = newValue;
        } else if (type == "adoptado") {
            ll_d->second.S_adop = newValue;
        } else if (type == "salida") {
            ll_d->second.cm_out = newValue;
        } else if (type == "medica") {
            ll_d->second.rv_healht = newValue;
        } else if (type == "vacuna") {
            ll_d->second.vacuna = newValue;
        } else {
            print_text(5, 6, "\t\t Tipo de dato no válido.");
        }
    }
}

void cats_inf(string code, const Cat_database& cat_slc) {
    string select_option, new_sssname,opts_tclaa;
    int k_optsm;
    clean_screen();
    paint_table();
    print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
    print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
    print_text(5, 8, "[3]Edad: "+cat_slc.Age);
    print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
    print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
    print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
    print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
    print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
    print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
    print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
    print_text(5, 16, "\tIngrese el numero que desea modificar o 11 para volver:");
    do
    {
        select_option = read_string();
        if (check_val(select_option,1,11)){
            clean_screen();
            paint_table();
            print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
            print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
            print_text(5, 8, "[3]Edad: "+cat_slc.Age);
            print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
            print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
            print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
            print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
            print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
            print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
            print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
            print_text(5, 16, "\tIngrese correctamente el numero:");
        }
    } while (check_val(select_option,1,11));

    k_optsm = convert_to_int(select_option);

    switch (k_optsm)
    {
    case 1:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
        print_text(5, 8, "[3]Edad: "+cat_slc.Age);
        print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
        print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
        print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
        print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
        print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
        print_text(5, 16, "\tIngrese el nuevo nombre del gato:");
        do
        {
            new_sssname = read_string();
            if (valid_word(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
                print_text(5, 8, "[3]Edad: "+cat_slc.Age);
                print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
                print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
                print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
                print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
                print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
                print_text(5, 16, "\tIngrese un nombre correcto:");
            }
        } while (valid_word(new_sssname));
        print_text(5, 17, "\tSe cambio "+cat_slc.Name+" por "+new_sssname);
        change_cats(code, "nombre", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        cats_menu();
        break;
    case 2:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
        print_text(5, 8, "[3]Edad: "+cat_slc.Age);
        print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
        print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
        print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
        print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
        print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
        print_text(5, 16, "\tIngrese la nueva raza del gato:");
        do
        {
            new_sssname = read_string();
            if (valid_raza(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
                print_text(5, 8, "[3]Edad: "+cat_slc.Age);
                print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
                print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
                print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
                print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
                print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
                print_text(5, 16, "\tIngrese la raza correctamenete:");
            }
        } while (valid_raza(new_sssname));
        print_text(5, 17, "\tSe cambio "+cat_slc.Raza+" por "+new_sssname);
        change_cats(code, "raza", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        cats_menu();
        break;
    case 3:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
        print_text(5, 8, "[3]Edad: "+cat_slc.Age);
        print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
        print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
        print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
        print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
        print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
        print_text(5, 16, "\tIngrese la nueva edad del gato:");
        do
        {
            new_sssname = read_string();
            if (valid_number(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
                print_text(5, 8, "[3]Edad: "+cat_slc.Age);
                print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
                print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
                print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
                print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
                print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
                print_text(5, 16, "\tIngrese una edad correcta:");
            }
        } while (valid_number(new_sssname));
        print_text(5, 17, "\tSe cambio "+cat_slc.Age+" por "+convert_month(new_sssname));
        change_cats(code, "edad", convert_month(new_sssname));
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        cats_menu();
        break;
    case 4:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
        print_text(5, 8, "[3]Edad: "+cat_slc.Age);
        print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
        print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
        print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
        print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
        print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
        print_text(5, 16, "\tIngrese la nueva fecha de ingreso del gato:");
        do
        {
            new_sssname = read_string();
            if (valid_date(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
                print_text(5, 8, "[3]Edad: "+cat_slc.Age);
                print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
                print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
                print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
                print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
                print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
                print_text(5, 16, "\tIngrese una fecha correcta:");
            }
        } while (valid_date(new_sssname));
        print_text(5, 17, "\tSe cambio "+cat_slc.Date+" por "+new_sssname);
        change_cats(code, "fecha", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        cats_menu();
        break;
    case 5:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
        print_text(5, 8, "[3]Edad: "+cat_slc.Age);
        print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
        print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
        print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
        print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
        print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
        print_text(5, 16, "\tIngrese el nuevo sexo del gato:");
        do
        {
            new_sssname = read_string();
            if (valid_sex(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
                print_text(5, 8, "[3]Edad: "+cat_slc.Age);
                print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
                print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
                print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
                print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
                print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
                print_text(5, 16, "\tIngrese un valor correcto:");
            }
        } while (valid_sex(new_sssname));
        print_text(5, 17, "\tSe cambio "+cat_slc.Sex+" por "+convert_sex(new_sssname));
        change_cats(code, "sexo", convert_sex(new_sssname));
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        cats_menu();
        break;
    case 6:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
        print_text(5, 8, "[3]Edad: "+cat_slc.Age);
        print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
        print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
        print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
        print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
        print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
        print_text(5, 16, "\tIngrese si esta en adopcion o no:");
        do
        {
            new_sssname = read_string();
            if (valid_si_no(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
                print_text(5, 8, "[3]Edad: "+cat_slc.Age);
                print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
                print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
                print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
                print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
                print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
                print_text(5, 16, "\tIngrese Solo si o no :");
            }
        } while (valid_si_no(new_sssname));
        print_text(5, 17, "\tSe cambio "+cat_slc.Adopt+" por "+new_sssname);
        change_cats(code, "adopcion", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        cats_menu();
        break;
    case 7:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
        print_text(5, 8, "[3]Edad: "+cat_slc.Age);
        print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
        print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
        print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
        print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
        print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
        print_text(5, 16, "\tIngrese Si o No (Adoptado):");
        do
        {
            new_sssname = read_string();
            if (valid_si_no(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
                print_text(5, 8, "[3]Edad: "+cat_slc.Age);
                print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
                print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
                print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
                print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
                print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
                print_text(5, 16, "\tIngrese si o no:");
            }
        } while (valid_si_no(new_sssname));
        print_text(5, 17, "\tSe cambio "+cat_slc.S_adop+" por "+new_sssname);
        change_cats(code, "adoptado", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        cats_menu();
        break;
    case 8:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
        print_text(5, 8, "[3]Edad: "+cat_slc.Age);
        print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
        print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
        print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
        print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
        print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
        print_text(5, 16, "\tIngrese la fecha de salida del albergue del gato:");
        do
        {
            new_sssname = read_string();
            if (valid_date(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
                print_text(5, 8, "[3]Edad: "+cat_slc.Age);
                print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
                print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
                print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
                print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
                print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
                print_text(5, 16, "\tFecha de salida cuando fue adoptado:");
            }
        } while (valid_date(new_sssname));
        print_text(5, 17, "\tSe cambio "+cat_slc.cm_out+" por "+new_sssname);
        change_cats(code, "salida", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        cats_menu();
        break;
    case 9:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
        print_text(5, 8, "[3]Edad: "+cat_slc.Age);
        print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
        print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
        print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
        print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
        print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
        print_text(5, 16, "\tIngrese la ultima fecha de revision medica del gato:");
        do
        {
            new_sssname = read_string();
            if (valid_date(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
                print_text(5, 8, "[3]Edad: "+cat_slc.Age);
                print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
                print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
                print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
                print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
                print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
                print_text(5, 16, "\tIngrese una fecha:");
            }
        } while (valid_date(new_sssname));
        print_text(5, 17, "\tSe cambio "+cat_slc.rv_healht+" por "+new_sssname);
        change_cats(code, "medica", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        cats_menu();
        break;
    case 10:
        clean_screen();
        paint_table();
        print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
        print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
        print_text(5, 8, "[3]Edad: "+cat_slc.Age);
        print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
        print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
        print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
        print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
        print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
        print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
        print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
        print_text(5, 16, "\tIngrese vacunas del gato:");
        do
        {
            new_sssname = read_string();
            if (valid_word(new_sssname)){
                clean_screen();
                paint_table();
                print_text(5, 6, "[1]Datos de "+cat_slc.Name+"("+code+")");
                print_text(5, 7, "[2]Raza: "+cat_slc.Raza);
                print_text(5, 8, "[3]Edad: "+cat_slc.Age);
                print_text(5, 9, "[4]Ingreso: "+cat_slc.Date);
                print_text(5, 10, "[5]Sexo: "+cat_slc.Sex);
                print_text(5, 11, "[6]En Adopcion: "+cat_slc.Adopt);
                print_text(5, 12, "[7]Adoptado: "+cat_slc.S_adop);
                print_text(5, 13, "[8]Salida: "+cat_slc.cm_out);
                print_text(5, 14, "[9]Revision medica(ultima): "+cat_slc.rv_healht);
                print_text(5, 15, "[10]Vacunas: "+cat_slc.vacuna);
                print_text(5, 16, "\tIngrese nombre de la vacuna:");
            }
        } while (valid_word(new_sssname));
        print_text(5, 17, "\tSe cambio "+cat_slc.vacuna+" por "+new_sssname);
        change_cats(code, "vacuna", new_sssname);
        print_text(5, 18, "Ingrese un valor para volver:");
        do
        {
            opts_tclaa = read_string();
            if (back_menu_check(opts_tclaa)){
                print_text(5, 18, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_tclaa));
        cats_menu();
    case 11:
        cats_menu();
        break;
    }
}

void status_cats(){
    string ing_dato;
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t Ingrese el codigo de un gato:");
    ing_dato = read_string();
    auto ll_d = dbase.find(ing_dato);
    if (ll_d != dbase.end()) {
        // Si se encuentra el animal, mostrar sus datos
        cats_inf(ing_dato,ll_d->second);
    } else {
        // Si no se encuentra el animal, mostrar un mensaje de error
        print_text(5, 6, "\t\t No se encontro los datos:");
    }
}
