#include <iostream>
#include "my_lib.h"

#include <string> // para var cadenas

// #include <windows.h> //Cursor
// #include <map> //DB
// // #include <cctype> // Incluye la biblioteca cctype para detectar vars M-m-n
// #include <sstream> // gennumeros ostringstream
// #include <iomanip> // gen numer setfill  setw
#include <conio.h>  // Necesario para getch()

using namespace std;

void menu();
void dogs_menu();
void add_dogs();
void cats_menu();
void add_cats();

void add_cats(){
    string cat_code,cat_name,cat_breed,cat_age,cat_date,cat_sex,esc_opts,o_cat_add;
    int opts_fnl;
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t GATOS");
    cat_code = generator_code_cats();
    print_text(5, 6, "Codigo:" + cat_code); // generar automaticamente 
    print_text(5, 8, "Nombre (Solo un nombre):");
    do
    {
        cat_name = read_string();
        if (valid_word(cat_name)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t GATOS");
            print_text(5, 6, "Codigo:" + cat_code);
            print_text(5, 8, "Nombre (Ingrese un nombre correctamente):");
        }
    } while (valid_word(cat_name));
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t GATOS");
    print_text(5, 6, "Codigo:" + cat_code);
    print_text(5, 8, "Nombre:" + cat_name);
    print_text(5, 10, "Raza (raza del gato):");
    do
    {
        // cat_breed = read_string();
        getline(cin,cat_breed);
        if (valid_raza(cat_breed)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t GATOS");
            print_text(5, 6, "Codigo:" + cat_code);
            print_text(5, 8, "Nombre:" + cat_name);
            print_text(5, 10, "Raza (Si no sabe solo ingresar el nombre):");
        }
    } while (valid_raza(cat_breed));
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t GATOS");
    print_text(5, 6, "Codigo:" + cat_code);
    print_text(5, 8, "Nombre:" + cat_name);
    print_text(5, 10, "Raza:" + cat_breed);
    print_text(5, 12, "Edad (En meses solo numeros):");
    do
    {
        cat_age = read_string();
        if (valid_number(cat_age)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t GATOS");
            print_text(5, 6, "Codigo:" + cat_code);
            print_text(5, 8, "Nombre:" + cat_name);
            print_text(5, 10, "Raza:" + cat_breed);
            print_text(5, 12, "Edad (Ingrese correctamente solo se considerara numeros):");
        }
    } while (valid_number(cat_age));
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t GATOS");
    print_text(5, 6, "Codigo:" + cat_code);
    print_text(5, 8, "Nombre:" + cat_name);
    print_text(5, 10, "Raza:" + cat_breed);
    print_text(5, 12, "Edad:" + convert_month(cat_age));
    print_text(5, 14, "Fecha de Ingreso (dd/mm/yy):");
    do
    {
        cat_date = read_string();
        if (valid_date(cat_date)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t GATOS");
            print_text(5, 6, "Codigo:" + cat_code);
            print_text(5, 8, "Nombre:" + cat_name);
            print_text(5, 10, "Raza:" + cat_breed);
            print_text(5, 12, "Edad:" + convert_month(cat_age));
            print_text(5, 14, "Fecha de Ingreso (dd/mm/yy):");
        }
    } while (valid_date(cat_date));
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t GATOS");
    print_text(5, 6, "Codigo:" + cat_code);
    print_text(5, 8, "Nombre:" + cat_name);
    print_text(5, 10, "Raza:" + cat_breed);
    print_text(5, 12, "Edad:" + convert_month(cat_age));
    print_text(5, 14, "Fecha de Ingreso:" + cat_date);
    print_text(5, 16, "Sexo (macho o hembra - m o h):");
    do
    {
        cat_sex = read_string();
        if (valid_sex(cat_sex)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t GATOS");
            print_text(5, 6, "Codigo:" + cat_code);
            print_text(5, 8, "Nombre:" + cat_name);
            print_text(5, 10, "Raza:" + cat_breed);
            print_text(5, 12, "Edad:" + convert_month(cat_age));
            print_text(5, 14, "Fecha de Ingreso:" + cat_date);
            print_text(5, 16, "Sexo(M o H - m o h):");
        }
    } while (valid_sex(cat_sex));
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t GATOS");
    print_text(5, 6, "Codigo:" + cat_code);
    print_text(5, 8, "Nombre:" + cat_name);
    print_text(5, 10, "Raza:" + cat_breed);
    print_text(5, 12, "Edad:" + convert_month(cat_age));
    print_text(5, 14, "Fecha de Ingreso:" + cat_date);
    print_text(5, 16, "Sexo:" + convert_sex(cat_sex));
    print_text(5, 18, "Agregar(Si o No):");
    do
    {
        esc_opts = read_string();
        if (check_menu(esc_opts)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t GATOS");
            print_text(5, 6, "Codigo:" + cat_code);
            print_text(5, 8, "Nombre:" + cat_name);
            print_text(5, 10, "Raza:" + cat_breed);
            print_text(5, 12, "Edad:" + convert_month(cat_age));
            print_text(5, 14, "Fecha de Ingreso:" + cat_date);
            print_text(5, 16, "Sexo:" + convert_sex(cat_sex));
            print_text(5, 18, "Agregar(Si o No):");
        }
    } while (check_menu(esc_opts));

    // Convertir la respuesta a minúsculas para comparación
    for (char &c : esc_opts) {
        c = tolower(c);
    }
    switch (esc_opts[0]) // Solo utilizamos la primera letra de lo ingresa 
    {
    case 's':
        ingresarDatos_cats(cat_code,cat_name,cat_breed,convert_month(cat_age),cat_date,convert_sex(cat_sex));
        clean_screen();
        paint_table();
        print_text(5, 4, "\t\t GATOS");
        print_text(5, 6, "Codigo:" + cat_code);
        print_text(5, 8, "Nombre:" + cat_name);
        print_text(5, 10, "Raza:" + cat_breed);
        print_text(5, 12, "Edad:" + convert_month(cat_age));
        print_text(5, 14, "Fecha de Ingreso:" + cat_date);
        print_text(5, 16, "Sexo:" + convert_sex(cat_sex));
        print_text(5, 18, "Datos de "+cat_name+"("+cat_code+") Agregados");
        print_text(5, 20, "\tDesea Ingresar datos de otro gato ?");
        print_text(5, 22, "\t[1] Agregar");
        print_text(5, 24, "\t[2] Volver");
        print_text(5, 26, "\tElija una opcion:");
        do
        {
            o_cat_add = read_string();
            if (check_val(o_cat_add,1,2)){
                clean_screen();
                paint_table();
                print_text(5, 4, "\t\t GATOS");
                print_text(5, 6, "Codigo:" + cat_code);
                print_text(5, 8, "Nombre:" + cat_name);
                print_text(5, 10, "Raza:" + cat_breed);
                print_text(5, 12, "Edad:" + convert_month(cat_age));
                print_text(5, 14, "Fecha de Ingreso:" + cat_date);
                print_text(5, 16, "Sexo:" + convert_sex(cat_sex));
                print_text(5, 18, "Datos de "+cat_name+"("+cat_code+") Agregados");
                print_text(5, 20, "\tDesea Ingresar datos de otro gato ?");
                print_text(5, 22, "\t[1] Agregar");
                print_text(5, 24, "\t[2] Volver");
                print_text(5, 26, "\tElija una opcion:");
            }
        } while (check_val(o_cat_add,1,2));
        opts_fnl = convert_to_int(o_cat_add);
        if (opts_fnl == 1){
            add_cats();
            break;
        }
        else if (opts_fnl == 2){
            cats_menu();
            break;
        }
    case 'n':
        clean_screen();
        paint_table();
        print_text(5, 4, "\t\t GATOS");
        print_text(5, 6, "Codigo:" + cat_code);
        print_text(5, 8, "Nombre:" + cat_name);
        print_text(5, 10, "Raza:" + cat_breed);
        print_text(5, 12, "Edad:" + convert_month(cat_age));
        print_text(5, 14, "Fecha de Ingreso:" + cat_date);
        print_text(5, 16, "Sexo:" + convert_sex(cat_sex));
        print_text(5, 18, "No se guardaron estos datos");
        print_text(5, 20, "\tDesea Ingresar datos de otro perro ?");
        print_text(5, 22, "\t[1] Agregar");
        print_text(5, 24, "\t[2] Volver");
        print_text(5, 26, "\tElija una opcion:");
        do
        {
            o_cat_add = read_string();
            if (check_val(o_cat_add,1,2)){
                clean_screen();
                paint_table();
                print_text(5, 4, "\t\t GATOS");
                print_text(5, 6, "Codigo:" + cat_code);
                print_text(5, 8, "Nombre:" + cat_name);
                print_text(5, 10, "Raza:" + cat_breed);
                print_text(5, 12, "Edad:" + convert_month(cat_age));
                print_text(5, 14, "Fecha de Ingreso:" + cat_date);
                print_text(5, 16, "Sexo:" + convert_sex(cat_sex));
                print_text(5, 18, "No se guardaron estos datos");
                print_text(5, 20, "\tDesea Ingresar datos de otro perro ?");
                print_text(5, 22, "\t[1] Agregar");
                print_text(5, 24, "\t[2] Volver");
                print_text(5, 26, "\tElija una opcion:");
            }
        } while (check_val(o_cat_add,1,2));
        opts_fnl = convert_to_int(o_cat_add);
        if (opts_fnl == 1){
            add_cats();
            break;
        }
        else if (opts_fnl == 2){
            cats_menu();
            break;
        }
    }
}

void cats_menu(){
    string val_cats,opts_mnl;
    int slct_opts;
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t GATOS");
    print_text(5, 8, "[1] Agregar");
    print_text(5, 10, "[2] Estado o Modificar");
    print_text(5, 12, "[3] Listar");
    print_text(5, 14, "[4] Volver");
    print_text(5, 18, "Ingrese opcion:");
    do
    {
        val_cats = read_string();

        if (check_val(val_cats,1,4)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t GATOS");
            print_text(5, 8, "[1] Agregar");
            print_text(5, 10, "[2] Estado o Modificar");
            print_text(5, 12, "[3] Listar");
            print_text(5, 14, "[4] Volver");
            print_text(5, 18, "Ingrese una opcion correcta:");
        }
    } while (check_val(val_cats,1,4));

    slct_opts = convert_to_int(val_cats);

    switch (slct_opts){
    case 1:
        add_cats();
        break;
    case 2:
        status_cats();
        break;
    case 3:
        mostrarDatos_gatos();
        print_text(5, 28, "Ingrese un valor para volver:");
        do
        {
            opts_mnl = read_string();
            if (back_menu_check(opts_mnl)){
                print_text(5, 28, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(opts_mnl));
        cats_menu();
        break;
    case 4:
        menu();
    }
}

void add_dogs(){
    string dog_code,dog_name,dog_breed,dog_age,dog_date,dog_sex,yes_or_no,add_other;
    int opts_add;
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t PERROS");
    dog_code = generator_code_dogs();
    print_text(5, 6, "Codigo:" + dog_code); // generar automaticamente 
    print_text(5, 8, "Nombre (Solo un nombre):");
    do
    {
        dog_name = read_string();
        if (valid_word(dog_name)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t PERROS");
            print_text(5, 6, "Codigo:" + dog_code);
            print_text(5, 8, "Nombre (Ingrese un nombre correctamente):");
        }
    } while (valid_word(dog_name));
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t PERROS");
    print_text(5, 6, "Codigo:" + dog_code);
    print_text(5, 8, "Nombre:" + dog_name);
    print_text(5, 10, "Raza (raza del perro):");
    do
    {
        // dog_breed = read_string();
        getline(cin,dog_breed);
        if (valid_raza(dog_breed)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t PERROS");
            print_text(5, 6, "Codigo:" + dog_code);
            print_text(5, 8, "Nombre:" + dog_name);
            print_text(5, 10, "Raza (Si no sabe solo ingresar el nombre):");
        }
    } while (valid_raza(dog_breed));
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t PERROS");
    print_text(5, 6, "Codigo:" + dog_code);
    print_text(5, 8, "Nombre:" + dog_name);
    print_text(5, 10, "Raza:" + dog_breed);
    print_text(5, 12, "Edad (En meses solo numeros):");
    do
    {
        dog_age = read_string();
        if (valid_number(dog_age)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t PERROS");
            print_text(5, 6, "Codigo:" + dog_code);
            print_text(5, 8, "Nombre:" + dog_name);
            print_text(5, 10, "Raza:" + dog_breed);
            print_text(5, 12, "Edad (Ingrese correctamente solo se considerara numeros):");
        }
    } while (valid_number(dog_age));
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t PERROS");
    print_text(5, 6, "Codigo:" + dog_code);
    print_text(5, 8, "Nombre:" + dog_name);
    print_text(5, 10, "Raza:" + dog_breed);
    print_text(5, 12, "Edad:" + convert_month(dog_age));
    print_text(5, 14, "Fecha de Ingreso (dd/mm/yy):");
    do
    {
        dog_date = read_string();
        if (valid_date(dog_date)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t PERROS");
            print_text(5, 6, "Codigo:" + dog_code);
            print_text(5, 8, "Nombre:" + dog_name);
            print_text(5, 10, "Raza:" + dog_breed);
            print_text(5, 12, "Edad:" + convert_month(dog_age));
            print_text(5, 14, "Fecha de Ingreso (dd/mm/yy):");
        }
    } while (valid_date(dog_date));
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t PERROS");
    print_text(5, 6, "Codigo:" + dog_code);
    print_text(5, 8, "Nombre:" + dog_name);
    print_text(5, 10, "Raza:" + dog_breed);
    print_text(5, 12, "Edad:" + convert_month(dog_age));
    print_text(5, 14, "Fecha de Ingreso:" + dog_date);
    print_text(5, 16, "Sexo (macho o hembra - m o h):");
    do
    {
        dog_sex = read_string();
        if (valid_sex(dog_sex)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t PERROS");
            print_text(5, 6, "Codigo:" + dog_code);
            print_text(5, 8, "Nombre:" + dog_name);
            print_text(5, 10, "Raza:" + dog_breed);
            print_text(5, 12, "Edad:" + convert_month(dog_age));
            print_text(5, 14, "Fecha de Ingreso:" + dog_date);
            print_text(5, 16, "Sexo(M o H - m o h):");
        }
    } while (valid_sex(dog_sex));
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t PERROS");
    print_text(5, 6, "Codigo:" + dog_code);
    print_text(5, 8, "Nombre:" + dog_name);
    print_text(5, 10, "Raza:" + dog_breed);
    print_text(5, 12, "Edad:" + convert_month(dog_age));
    print_text(5, 14, "Fecha de Ingreso:" + dog_date);
    print_text(5, 16, "Sexo:" + convert_sex(dog_sex));
    print_text(5, 18, "Agregar(Si o No):");
    do
    {
        yes_or_no = read_string();
        if (check_menu(yes_or_no)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t PERROS");
            print_text(5, 6, "Codigo:" + dog_code);
            print_text(5, 8, "Nombre:" + dog_name);
            print_text(5, 10, "Raza:" + dog_breed);
            print_text(5, 12, "Edad:" + convert_month(dog_age));
            print_text(5, 14, "Fecha de Ingreso:" + dog_date);
            print_text(5, 16, "Sexo:" + convert_sex(dog_sex));
            print_text(5, 18, "Agregar(Si o No):");
        }
    } while (check_menu(yes_or_no));

    // Convertir la respuesta a minúsculas para comparación
    for (char &c : yes_or_no) {
        c = tolower(c);
    }
    switch (yes_or_no[0]) // Solo utilizamos la primera letra de lo ingresa 
    {
    case 's':
        ingresarDatos_dogs(dog_code,dog_name,dog_breed,convert_month(dog_age),dog_date,convert_sex(dog_sex));
        clean_screen();
        paint_table();
        print_text(5, 4, "\t\t PERROS");
        print_text(5, 6, "Codigo:" + dog_code);
        print_text(5, 8, "Nombre:" + dog_name);
        print_text(5, 10, "Raza:" + dog_breed);
        print_text(5, 12, "Edad:" + convert_month(dog_age));
        print_text(5, 14, "Fecha de Ingreso:" + dog_date);
        print_text(5, 16, "Sexo:" + convert_sex(dog_sex));
        print_text(5, 18, "Datos de "+dog_name+"("+dog_code+") Agregados");
        print_text(5, 20, "\tDesea Ingresar datos de otro perro ?");
        print_text(5, 22, "\t[1] Agregar");
        print_text(5, 24, "\t[2] Volver");
        print_text(5, 26, "\tElija una opcion:");
        do
        {
            add_other = read_string();
            if (check_val(add_other,1,2)){
                clean_screen();
                paint_table();
                print_text(5, 4, "\t\t PERROS");
                print_text(5, 6, "Codigo:" + dog_code);
                print_text(5, 8, "Nombre:" + dog_name);
                print_text(5, 10, "Raza:" + dog_breed);
                print_text(5, 12, "Edad:" + convert_month(dog_age));
                print_text(5, 14, "Fecha de Ingreso:" + dog_date);
                print_text(5, 16, "Sexo:" + convert_sex(dog_sex));
                print_text(5, 18, "Datos de "+dog_name+"("+dog_code+") Agregados");
                print_text(5, 20, "\tDesea Ingresar datos de otro perro ?");
                print_text(5, 22, "\t[1] Agregar");
                print_text(5, 24, "\t[2] Volver");
                print_text(5, 26, "\tElija una opcion:");
            }
        } while (check_val(add_other,1,2));
        opts_add = convert_to_int(add_other);
        if (opts_add == 1){
            add_dogs();
            break;
        }
        else if (opts_add == 2){
            dogs_menu();
            break;
        }
    case 'n':
        clean_screen();
        paint_table();
        print_text(5, 4, "\t\t PERROS");
        print_text(5, 6, "Codigo:" + dog_code);
        print_text(5, 8, "Nombre:" + dog_name);
        print_text(5, 10, "Raza:" + dog_breed);
        print_text(5, 12, "Edad:" + convert_month(dog_age));
        print_text(5, 14, "Fecha de Ingreso:" + dog_date);
        print_text(5, 16, "Sexo:" + convert_sex(dog_sex));
        print_text(5, 18, "No se guardaron estos datos");
        print_text(5, 20, "\tDesea Ingresar datos de otro perro ?");
        print_text(5, 22, "\t[1] Agregar");
        print_text(5, 24, "\t[2] Volver");
        print_text(5, 26, "\tElija una opcion:");
        do
        {
            add_other = read_string();
            if (check_val(add_other,1,2)){
                clean_screen();
                paint_table();
                print_text(5, 4, "\t\t PERROS");
                print_text(5, 6, "Codigo:" + dog_code);
                print_text(5, 8, "Nombre:" + dog_name);
                print_text(5, 10, "Raza:" + dog_breed);
                print_text(5, 12, "Edad:" + convert_month(dog_age));
                print_text(5, 14, "Fecha de Ingreso:" + dog_date);
                print_text(5, 16, "Sexo:" + convert_sex(dog_sex));
                print_text(5, 18, "No se guardaron estos datos");
                print_text(5, 20, "\tDesea Ingresar datos de otro perro ?");
                print_text(5, 22, "\t[1] Agregar");
                print_text(5, 24, "\t[2] Volver");
                print_text(5, 26, "\tElija una opcion:");
            }
        } while (check_val(add_other,1,2));
        opts_add = convert_to_int(add_other);
        if (opts_add == 1){
            add_dogs();
            break;
        }
        else if (opts_add == 2){
            dogs_menu();
            break;
        }
    }
}

void dogs_menu(){
    string val_dogs,menu_list;
    int select_opts;
    clean_screen();
    paint_table();
    print_text(5, 4, "\t\t PERROS");
    print_text(5, 8, "[1] Agregar");
    print_text(5, 10, "[2] Estado o Modificar");
    print_text(5, 12, "[3] Listar");
    print_text(5, 14, "[4] Volver");
    print_text(5, 18, "Ingrese opcion:");
    do
    {
        val_dogs = read_string();

        if (check_val(val_dogs,1,4)){
            clean_screen();
            paint_table();
            print_text(5, 4, "\t\t PERROS");
            print_text(5, 8, "[1] Agregar");
            print_text(5, 10, "[2] Estado o Modificar");
            print_text(5, 12, "[3] Listar");
            print_text(5, 14, "[4] Volver");
            print_text(5, 18, "Ingrese una opcion correcta:");
        }
    } while (check_val(val_dogs,1,4));

    select_opts = convert_to_int(val_dogs);

    switch (select_opts){
    case 1:
        add_dogs();
        break;
    case 2:
        status_dogs();
        break;
    case 3:
        mostrarDatos_perros();
        print_text(5, 28, "Ingrese un valor para volver:");
        do
        {
            menu_list = read_string();
            if (back_menu_check(menu_list)){
                print_text(5, 28, "Ingrese un valor para volver:");
            }
        } while (back_menu_check(menu_list));
        dogs_menu();
        break;
    case 4:
        menu();
    }
}

void menu(){
    string option_1;
    clean_screen();
    paint_table();
    print_text(5, 4, "[1] Perros");
    print_text(5, 6, "[2] Gatos");
    print_text(5, 8, "[3] Salir");
    print_text(5, 10, "Ingrese opcion:");
    // SetCursorPosition(21, 5); // Poner el cursor en la parte donde pide ingresar opcion
    SetCursorPosition(21, 10); // Poner el cursor en la parte donde pide ingresar opcion
    do
    {
        option_1 = read_string();

        if (check_val(option_1,1,3)){
            clean_screen();
            paint_table();
            print_text(5, 4, "[1] Perros");
            print_text(5, 6, "[2] Gatos");
            print_text(5, 8, "[3] Salir");
            print_text(5, 10, "Ingresa una opcion correcta:");
        }
    } while (check_val(option_1,1,3));

    int select_option = convert_to_int(option_1);

    switch (select_option){
    case 1:
        dogs_menu();
        break;
    case 2:
        cats_menu();
        break;
    case 3:
        close_program();
    }
}

int main() {
    system("mode con: cols=130 lines=30"); // Cambiar el tamaño de la consola

    menu();
    // cin.get();// Esperar a que el usuario presione una tecla antes de salir

    system("pause");
    return 0;
}