#include "Gimnasio.h"

Gimnasio::Gimnasio() : capacidadSucursales(30), numSucursales(0) {
    sucursales = new Sucursal * [capacidadSucursales];
    cargarDatosIniciales();
}

void Gimnasio::cargarDatosIniciales() {
    // Crear 10 sucursales 
    string sucursalesData[10][4] = {
        {"SJ001", "San Jose", "San Jose", "2222-1111"},
        {"SJ002", "San Jose", "Escazu", "2221-1111"},
        {"SJ003", "San Jose", "Desamparados", "2225-1111"},
        {"AL001", "Alajuela", "Alajuela", "2442-1111"},
        {"AL002", "Alajuela", "Grecia", "2443-1111"},
        {"CA001", "Cartago", "Turrialba", "2590-1111"},
        {"HE001", "Heredia", "Flores", "2260-1111"},
        {"GU001", "Guanacaste", "Liberia", "2666-1111"},
        {"PU001", "Puntarenas", "Garabito", "2631-1111"},
        {"LI001", "Limon", "Matina", "2758-1111"}
    };
    for (int i = 0; i < 10; i++) {
        sucursales[numSucursales++] = new Sucursal(
            sucursalesData[i][0],
            sucursalesData[i][1],
            sucursalesData[i][2],
            sucursalesData[i][3]
        );
    }

    // Agregar instructores de prueba a varias sucursales
    Instructor* instr1 = new Instructor("119230385", "Carlos Arguedas", "8825-3458", "carlos@powerlab.com", "15/03/1985");
    instr1->agregarEspecialidad("Pesas");
    sucursales[0]->agregarInstructor(instr1);

    Instructor* instr2 = new Instructor("204250912", "Jimena Espinoza", "7724-0318", "maria@powerlab.com", "20/08/1990");
    instr2->agregarEspecialidad("Yoga");
    instr2->agregarEspecialidad("Zumba");
    sucursales[0]->agregarInstructor(instr2);

    Instructor* instr3 = new Instructor("325400812", "Pedro Ramirez", "6318-4023", "pedro@powerlab.com", "10/12/1996");
    instr3->agregarEspecialidad("Cardio");
    instr3->agregarEspecialidad("Spinning");
    sucursales[1]->agregarInstructor(instr3);


    // Agregar clientes de prueba
    Cliente* cliente1 = new Cliente("123456789", "Juan Perez", "60230318", "juan@email.com", "10/05/1995", "M", "01/08/2023", instr1);
    sucursales[0]->agregarCliente(cliente1);

    Cliente* cliente2 = new Cliente("387654321", "Ana Rodriguez", "5540-6870", "ana@email.com", "25/11/1998", "F", "02/01/2024", instr2);
    sucursales[0]->agregarCliente(cliente2);

    Cliente* cliente3 = new Cliente("456123789", "Luis Gonzalez", "8369-6845", "luis@email.com", "15/07/1990", "M", "03/03/2025", instr3);
    sucursales[1]->agregarCliente(cliente3);
}
    







    Gimnasio::~Gimnasio () {
    for (int i = 0; i < numSucursales; i++) {
        delete sucursales[i];
    }
    delete[] sucursales;
}

void Gimnasio::agregarSucursal() {
    if (numSucursales >= capacidadSucursales) {
        cout << "Limite de sucursales. No se pueden agregar mas." << endl;
        return;
    }

    string codigo, provincia, canton, telefono;

    cout << "\n----- Agregar Nueva Sucursal -----" << endl;
    do{
        cout << "Codigo (5 digitos): ";
    cin.ignore();
    getline(cin, codigo);
    if (codigo.length() != 5) {
        cout << "Error: El codigo debe tener exactamente 5 digitos." << endl;
    }
} while (codigo.length() != 5);
    cout << "Provincia: ";
    getline(cin, provincia);
    cout << "Canton: ";
    getline(cin, canton);
    cout << "Telefono: ";
    getline(cin, telefono);

    sucursales[numSucursales++] = new Sucursal(codigo, provincia, canton, telefono);
    cout << "Sucursal agregada correctamente." << endl;
}

void Gimnasio::mostrarMenuPrincipal() const {
    cout << "\n===== GYM PowerLab =====" << endl;
    cout << "  -----Bienvenido-----" << endl;
    cout << "Sucursales registradas: " << numSucursales << endl;
    cout << "1. Agregar Sucursal" << endl;
    cout << "2. Lista Sucursales" << endl;
    cout << "3. Gestionar Sucursal" << endl;
    cout << "4. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

void Gimnasio::listarSucursales() const {
    cout << "\n----- Sucursales de PowerLab -----" << endl;
    for (int i = 0; i < numSucursales; i++) {
        cout << i + 1 << ". ";
        sucursales[i]->mostrarInfo();
    }
}

void Gimnasio::gestionarSucursal() {
    if (numSucursales == 0) {
        cout << "No hay sucursales registradas." << endl;
        return;
    }

    listarSucursales();
    cout << "Seleccione el numero de sucursal a gestionar: ";
    int opcion;
    cin >> opcion;

    if (opcion < 1 || opcion > numSucursales) {
        cout << "Opcion invalida." << endl;
        return;
    }

    Sucursal* sucursal = sucursales[opcion - 1];
    menuGestionSucursal(sucursal);
}

void Gimnasio::menuGestionSucursal(Sucursal* sucursal) {
    int opcion;
    do {
        cout << "\n=== GESTION SUCURSAL " << sucursal->getCodigo() << " ===" << endl;
        cout << "1. Agregar Instructor" << endl;
        cout << "2. Agregar Cliente" << endl;
        cout << "3. Lista Instructores" << endl;
        cout << "4. Lista Clientes" << endl;
        cout << "5. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: agregarInstructor(sucursal); break;
        case 2: agregarCliente(sucursal); break;
        case 3: sucursal->listarInstructores(); break;
        case 4: sucursal->listarClientes(); break;
        case 5: cout << "Volviendo al menu principal..." << endl; break;
        default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 5);
}

void Gimnasio::agregarInstructor(Sucursal* sucursal) {
    string cedula, nombre, telefono, correo, fechaNacimiento;

    cout << "\n--- Agregar Instructor ---" << endl;
    cout << "Cedula: ";
    cin.ignore();
    getline(cin, cedula);
    cout << "Nombre completo: ";
    getline(cin, nombre);
    cout << "Telefono: ";
    getline(cin, telefono);
    cout << "Correo: ";
    getline(cin, correo);
    cout << "Fecha de nacimiento (dd/mm/aaaa): ";
    getline(cin, fechaNacimiento);

    Instructor* nuevoInstructor = new Instructor(cedula, nombre, telefono, correo, fechaNacimiento);

    // Agregar especialidades
    string especialidades[] = { "CrossFit", "HIIT", "TRX", "Pesas", "Spinning", "Cardio", "Yoga", "Zumba" };
    int numEspecialidades = 8;

    cout << "\nEspecialidades disponibles:" << endl;
    for (int i = 0; i < numEspecialidades; i++) {
        cout << i + 1 << ". " << especialidades[i] << endl;
    }

    cout << "¿Cuantas especialidades tiene el instructor? (1-" << numEspecialidades << "): ";
    int cantidad;
    cin >> cantidad;

    if (cantidad < 1 || cantidad > numEspecialidades) {
        cout << "Cantidad invalida." << endl;
        cantidad = 1;
    }

    for (int i = 0; i < cantidad; i++) {
        cout << "Seleccione la especialidad " << i + 1 << " (1-8): ";
        int opcion;
        cin >> opcion;

        if (opcion >= 1 && opcion <= numEspecialidades) {
            nuevoInstructor->agregarEspecialidad(especialidades[opcion - 1]);
        }
        else {
            cout << "Opcion invalida. Se asignara CrossFit por defecto." << endl;
            nuevoInstructor->agregarEspecialidad("CrossFit");
        }
    }

    sucursal->agregarInstructor(nuevoInstructor);
}

void Gimnasio::agregarCliente(Sucursal* sucursal) {
    if (sucursal->getNumInstructores() == 0) {
        cout << "No hay instructores disponibles. Primero agregue instructores." << endl;
        return;
    }

    string cedula, nombre, telefono, correo, fechaNacimiento, sexo, fechaInscripcion;

    cout << "\n--- Agregar Cliente ---" << endl;
    cout << "Cedula: ";
    cin.ignore();
    getline(cin, cedula);
    cout << "Nombre completo: ";
    getline(cin, nombre);
    cout << "Telefono: ";
    getline(cin, telefono);
    cout << "Correo electronico: ";
    getline(cin, correo);
    cout << "Fecha de nacimiento (dd/mm/aaaa): ";
    getline(cin, fechaNacimiento);
    cout << "Sexo (M/F/O): ";
    getline(cin, sexo);
    cout << "Fecha de inscripcion (dd/mm/aaaa): ";
    getline(cin, fechaInscripcion);

    sucursal->listarInstructores();
    cout << "Seleccione el numero del instructor a asignar: ";
    int opcionInstructor;
    cin >> opcionInstructor;

    Instructor* instructorSeleccionado = sucursal->getInstructor(opcionInstructor - 1);
    if (instructorSeleccionado) {
        Cliente* nuevoCliente = new Cliente(cedula, nombre, telefono, correo, fechaNacimiento, sexo, fechaInscripcion,instructorSeleccionado);
        sucursal->agregarCliente(nuevoCliente);
    }
    else {
        cout << "Instructor no valido." << endl;
    }
}

void Gimnasio::ejecutar() {
    int opcion;
    do {
        mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
        case 1: agregarSucursal(); break;
        case 2: listarSucursales(); break;
        case 3: gestionarSucursal(); break;
        case 4: cout << "Saliendo del sistema..." << endl; break;
        default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);
}
