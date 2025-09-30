#include "Gimnasio.h"
#include <iostream>

using namespace std;

Gimnasio::Gimnasio() : capacidadSucursales(30), numSucursales(0), capacidadMediciones(1000), numMediciones(0),
                       capacidadEjercicios(100), numEjercicios(0), capacidadRutinas(500), numRutinas(0),
                       capacidadClasesG(8), numClasesG(0){

    sucursales = new Sucursal * [capacidadSucursales];
    historialMediciones = new Medicion * [capacidadMediciones];
    bateriaEjercicios = new Ejercicio * [capacidadEjercicios];
    rutinaActual = new Rutina * [capacidadRutinas];

    cargarDatosIniciales();
}

void Gimnasio::cargarDatosIniciales() {
    // Crear 10 sucursales 
    string sucursalesData[10][5] = {
        {"SJ001", "San Jose", "San Jose", "2222-1111", "sanjose@powerlab.com"},
        {"SJ002", "San Jose", "Escazu", "2221-1111", "escazu@powerlab.com"},
        {"SJ003", "San Jose", "Desamparados", "2225-1111", "desamparados@powerlab.com"},
        {"AL001", "Alajuela", "Alajuela", "2442-1111", "alajuela@powerlab.com"},
        {"AL002", "Alajuela", "Grecia", "2443-1111", "grecia@powerlab.com"},
        {"CA001", "Cartago", "Turrialba", "2590-1111", "turrialba@powerlab.com"},
        {"HE001", "Heredia", "Flores", "2260-1111", "flores@powerlab.com"},
        {"GU001", "Guanacaste", "Liberia", "2666-1111", "liberia@powerlab.com"},
        {"PU001", "Puntarenas", "Garabito", "2631-1111", "garabito@powerlab.com"},
        {"LI001", "Limon", "Matina", "2758-1111", "matina@powerlab.com"}
    };
    for (int i = 0; i < 10; i++) {
        sucursales[numSucursales++] = new Sucursal(
            sucursalesData[i][0],
            sucursalesData[i][1],
            sucursalesData[i][2],
            sucursalesData[i][3],
            sucursalesData[i][4]
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

    // Agregar ejercicios a la batería
    bateriaEjercicios[numEjercicios++] = new Ejercicio("Press de Banca", "Ejercicio para pectorales", "Pecho", "Barra", 4, 10);

    bateriaEjercicios[numEjercicios++] = new Ejercicio("Polea Superior", "Ejercicio para triceps", "Triceps", "Barra", 3, 12);

    bateriaEjercicios[numEjercicios++] = new Ejercicio("Curl de Biceps", "Ejercicio para biceps", "Biceps", "Mancuernas", 3, 12);

    bateriaEjercicios[numEjercicios++] = new Ejercicio("Sentadillas", "Ejercicio para piernas", "Piernas", "Ninguno", 4, 15);

    bateriaEjercicios[numEjercicios++] = new Ejercicio("Peso Muerto", "Ejercicio para espalda", "Espalda", "Pesas", 4, 15);
}

Gimnasio::~Gimnasio() {
    for (int i = 0; i < numSucursales; i++) {
        delete sucursales[i];
    }
    for (int i = 0; i < numEjercicios; i++) {
        delete bateriaEjercicios[i];
    }
    for (int i = 0; i < numMediciones; i++) {
        delete historialMediciones[i];
    }
    for (int i = 0; i < numRutinas; i++) {
        delete rutinaActual[i];
    }

    delete[] sucursales;
    delete[] bateriaEjercicios;
    delete[] historialMediciones;
    delete[] rutinaActual;
}

// ==================== GESTION DE SUCURSALES ====================
void Gimnasio::agregarSucursal() {
    if (numSucursales >= capacidadSucursales) {
        cout << "Limite de sucursales. No se pueden agregar mas." << endl;
        return;
    }

    string codigo, provincia, canton, telefono, correo;

    cout << "\n----- Agregar Nueva Sucursal -----" << endl;
    do {
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
    cout << "Correo: ";
    getline(cin, correo);

    sucursales[numSucursales++] = new Sucursal(codigo, provincia, canton, telefono, correo);
    cout << "Sucursal agregada correctamente." << endl;
}

void Gimnasio::listarSucursales() const {
    cout << "\n----- Sucursales de PowerLab -----" << endl;
    for (int i = 0; i < numSucursales; i++) {
        cout << i + 1 << ". ";
        sucursales[i]->mostrarInfo();
        cout << "----------------------------------" << endl;
    }
}

Sucursal* Gimnasio::seleccionarSucursal() {
    if (numSucursales == 0) {
        cout << "No hay sucursales registradas." << endl;
        return nullptr;
    }

    listarSucursales();
    cout << "Seleccione el numero de sucursal: ";
    int opcion;
    cin >> opcion;

    if (opcion < 1 || opcion > numSucursales) {
        cout << "Opcion invalida." << endl;
        return nullptr;
    }

    return sucursales[opcion - 1];
}

void Gimnasio::gestionarSucursal() {
    Sucursal* sucursal = seleccionarSucursal();
    if (sucursal != nullptr) {
        menuGestionSucursal(sucursal);
    }
}

void Gimnasio::menuGestionSucursal(Sucursal* sucursal) {
    if (sucursal == nullptr) return;

    int opcion;
    do {
        cout << "\n----- GESTION SUCURSAL " << sucursal->getCodigo() << " -----" << endl;
        cout << "1. Agregar Instructor" << endl;
        cout << "2. Agregar Cliente" << endl;
        cout << "3. Listar Instructores" << endl;
        cout << "4. Listar Clientes" << endl;
        cout << "5. Clases Grupales" << endl;
        cout << "6. Volver al menu principal" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: agregarInstructor(sucursal); break;
        case 2: agregarCliente(sucursal); break;
        case 3: listarInstructoresSucursal(sucursal); break;
        case 4: listarClientesSucursal(sucursal); break;
        case 5: menuClasesGrupales(sucursal); break;
        case 6: cout << "Volviendo al menu principal..." << endl; break;
        default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 6);
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
    cout << "Instructor agregado exitosamente!" << endl;
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

    Instructor* instructorSeleccionado = nullptr;
    Instructor** instructores = sucursal->obtenerInstructores();
    if (opcionInstructor >= 1 && opcionInstructor <= sucursal->getNumInstructores()) {
        instructorSeleccionado = instructores[opcionInstructor - 1];
    }

    if (instructorSeleccionado != nullptr) {
        Cliente* nuevoCliente = new Cliente(cedula, nombre, telefono, correo, fechaNacimiento, sexo, fechaInscripcion, instructorSeleccionado);
        sucursal->agregarCliente(nuevoCliente);
        cout << "Cliente agregado exitosamente!" << endl;
    }
    else {
        cout << "Instructor no valido." << endl;
    }
}

void Gimnasio::listarInstructoresSucursal(Sucursal* sucursal) const {
    if (sucursal != nullptr) {
        sucursal->listarInstructores();
    }
}

void Gimnasio::listarClientesSucursal(Sucursal* sucursal) const {
    if (sucursal != nullptr) {
        sucursal->listarClientes();
    }
}

// ==================== GESTION DE MEDICIONES ====================
void Gimnasio::menuMediciones() {
    int opcion;
    do {
        cout << "\n--- GESTION DE MEDICIONES ---" << endl;
        cout << "1. Agregar Medicion" << endl;
        cout << "2. Ver Historial de Cliente" << endl;
        cout << "3. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: agregarMedicionesCliente(); break;
        case 2: historialCliente(); break;
        case 3: break;
        default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 3);
}

void Gimnasio::agregarMedicionesCliente() {
    if (numSucursales == 0) {
        cout << "No hay sucursales registradas." << endl;
        return;
    }

    Sucursal* sucursal = seleccionarSucursal();
    if (sucursal == nullptr) return;

    if (sucursal->getNumClientes() == 0) {
        cout << "No hay clientes en esta sucursal." << endl;
        return;
    }

    // Seleccionar cliente
    sucursal->listarClientes();
    cout << "Seleccione el numero del cliente: ";
    int opcionCliente;
    cin >> opcionCliente;

    Cliente** clientes = sucursal->obtenerClientes();
    if (opcionCliente < 1 || opcionCliente > sucursal->getNumClientes()) {
        cout << "Opcion invalida." << endl;
        return;
    }

    Cliente* cliente = clientes[opcionCliente - 1];
    Instructor* instructor = cliente->getInstructor();

    if (instructor == nullptr) {
        cout << "El cliente no tiene instructor asignado." << endl;
        return;
    }

    // Ingresar datos de la medición
    string fecha;
    double peso, altura, porcentajeGrasa, porcentajeMusculo, grasaVisceral;
    double cintura, cadera, pecho, muslo;
    int edadMetabolismo;

    cout << "\n--- REGISTRAR MEDICIÓN ---" << endl;
    cout << "Cliente: " << cliente->getNombre() << endl;
    cout << "Instructor: " << instructor->getNombre() << endl;

    cout << "Fecha de medicion (dd/mm/aaaa): ";
    cin.ignore();
    getline(cin, fecha);
    cout << "Peso (kg): ";
    cin >> peso;
    cout << "Altura (m): ";
    cin >> altura;
    cout << "Porcentaje de grasa (%): ";
    cin >> porcentajeGrasa;
    cout << "Porcentaje de musculo (%): ";
    cin >> porcentajeMusculo;
    cout << "Grasa visceral (%): ";
    cin >> grasaVisceral;
    cout << "Medida de cintura (cm): ";
    cin >> cintura;
    cout << "Medida de cadera (cm): ";
    cin >> cadera;
    cout << "Medida de pecho (cm): ";
    cin >> pecho;
    cout << "Medida de muslo (cm): ";
    cin >> muslo;
    cout << "Edad metabolismo: ";
    cin >> edadMetabolismo;

    // Crear y registrar la medición
    Medicion* nuevaMedicion = new Medicion(cliente, instructor, fecha, peso, altura,
        porcentajeGrasa, porcentajeMusculo, grasaVisceral,
        cintura, cadera, pecho, muslo, edadMetabolismo);

    // Agregar al historial global
    if (numMediciones >= capacidadMediciones) {
        capacidadMediciones *= 2;
        Medicion** nuevo = new Medicion * [capacidadMediciones];
        for (int i = 0; i < numMediciones; i++) {
            nuevo[i] = historialMediciones[i];
        }
        delete[] historialMediciones;
        historialMediciones = nuevo;
    }
    historialMediciones[numMediciones++] = nuevaMedicion;

    cout << "\n--- REPORTE GENERADO ---" << endl;
    nuevaMedicion->reporte();
    cout << "Medicion registrada exitosamente!" << endl;
}

void Gimnasio::historialCliente() {
    if (numSucursales == 0) {
        cout << "No hay sucursales registradas." << endl;
        return;
    }

    Sucursal* sucursal = seleccionarSucursal();
    if (sucursal == nullptr) return;

    if (sucursal->getNumClientes() == 0) {
        cout << "No hay clientes en esta sucursal." << endl;
        return;
    }

    // Seleccionar cliente
    sucursal->listarClientes();
    cout << "Seleccione el numero del cliente: ";
    int opcionCliente;
    cin >> opcionCliente;

    Cliente** clientes = sucursal->obtenerClientes();
    if (opcionCliente < 1 || opcionCliente > sucursal->getNumClientes()) {
        cout << "Opcion invalida." << endl;
        return;
    }

    Cliente* cliente = clientes[opcionCliente - 1];

    // Buscar mediciones del cliente
    cout << "\n=== HISTORIAL DE MEDICIONES ===" << endl;
    cout << "Cliente: " << cliente->getNombre() << endl;
    cout << "Cedula: " << cliente->getCedula() << endl;

    bool encontrado = false;
    for (int i = 0; i < numMediciones; i++) {
        if (historialMediciones[i]->getCliente()->getCedula() == cliente->getCedula()) {
            cout << "\n--- Medicion " << i + 1 << " ---" << endl;
            historialMediciones[i]->reporte();
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No se encontraron mediciones para este cliente." << endl;
    }
}

// ==================== BATERÍA DE EJERCICIOS ====================
void Gimnasio::menuBateriaEjercicios() {
    int opcion;
    do {
        cout << "\n--- BATERIA DE EJERCICIOS ---" << endl;
        cout << "1. Agregar Ejercicio" << endl;
        cout << "2. Mostrar Todos los Ejercicios" << endl;
        cout << "3. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: agregarBateriaEjercicios(); break;
        case 2: mostrarBateriaEjercicios(); break;
        case 3: break;
        default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 3);
}

void Gimnasio::agregarBateriaEjercicios() {
    if (numEjercicios >= capacidadEjercicios) {
        capacidadEjercicios *= 2;
        Ejercicio** nuevo = new Ejercicio * [capacidadEjercicios];
        for (int i = 0; i < numEjercicios; i++) {
            nuevo[i] = bateriaEjercicios[i];
        }
        delete[] bateriaEjercicios;
        bateriaEjercicios = nuevo;
    }

    string nombre, descripcion, area, maquinas;
    int series, repeticiones;

    cout << "\n--- AGREGAR EJERCICIO A BATERÍA ---" << endl;
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Descripcion: ";
    getline(cin, descripcion);

    // Validar area
    string areasValidos[] = { "Pecho", "Triceps", "Biceps", "Piernas", "Espalda" };
    cout << "Areas disponibles: ";
    for (int i = 0; i < 5; i++) {
        cout << areasValidos[i] << (i < 4 ? ", " : "");
    }
    cout << "\nArea: ";
    getline(cin, area);

    cout << "Series: ";
    cin >> series;
    cout << "Repeticiones: ";
    cin >> repeticiones;
    cin.ignore();

    cout << "Maquinas: ";
    getline(cin, maquinas);

    Ejercicio* nuevoEjercicio = new Ejercicio(nombre, descripcion, area, maquinas, series, repeticiones);
    bateriaEjercicios[numEjercicios++] = nuevoEjercicio;
    cout << "Ejercicio agregado a la batería correctamente!" << endl;
}

void Gimnasio::mostrarBateriaEjercicios() const {
    cout << "\n=== BATERÍA DE EJERCICIOS ===" << endl;
    cout << "Total de ejercicios: " << numEjercicios << endl;

    if (numEjercicios == 0) {
        cout << "No hay ejercicios en la batería." << endl;
        return;
    }

    for (int i = 0; i < numEjercicios; i++) {
        cout << "\n--- Ejercicio " << i + 1 << " ---" << endl;
        bateriaEjercicios[i]->mostrarInfoCompleta();
    }
}

// ==================== GESTIÓN DE RUTINAS ====================
void Gimnasio::menuRutinas() {
    int opcion;
    do {
        cout << "\n--- GESTION DE RUTINAS ---" << endl;
        cout << "1. Crear Nueva Rutina" << endl;
        cout << "2. Mostrar Rutina de Cliente" << endl;
        cout << "3. Listar Todas las Rutinas Activas" << endl;
        cout << "4. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: agregarRutinaCliente(); break;
        case 2: mostrarRutinaCliente(); break;
        case 3: listarRutinasActivas(); break;
        case 4: break;
        default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);
}

void Gimnasio::agregarRutinaCliente() {
    if (numSucursales == 0) {
        cout << "No hay sucursales registradas." << endl;
        return;
    }

    Sucursal* sucursal = seleccionarSucursal();
    if (sucursal == nullptr) return;

    if (sucursal->getNumClientes() == 0) {
        cout << "No hay clientes en esta sucursal." << endl;
        return;
    }

    if (numEjercicios == 0) {
        cout << "No hay ejercicios en la batería. Primero agregue ejercicios." << endl;
        return;
    }

    // Seleccionar cliente
    sucursal->listarClientes();
    cout << "Seleccione el numero del cliente: ";
    int opcionCliente;
    cin >> opcionCliente;

    Cliente** clientes = sucursal->obtenerClientes();
    if (opcionCliente < 1 || opcionCliente > sucursal->getNumClientes()) {
        cout << "Opcion invalida." << endl;
        return;
    }

    Cliente* cliente = clientes[opcionCliente - 1];
    Instructor* instructor = cliente->getInstructor();

    if (instructor == nullptr) {
        cout << "El cliente no tiene instructor asignado." << endl;
        return;
    }

    // Crear nueva rutina
    string fecha;
    cout << "\n--- CREAR NUEVA RUTINA ---" << endl;
    cout << "Cliente: " << cliente->getNombre() << endl;
    cout << "Instructor: " << instructor->getNombre() << endl;
    cin.ignore();
    cout << "Fecha de asignacion (dd/mm/aaaa): ";
    getline(cin, fecha);

    Rutina* nuevaRutina = new Rutina(cliente, instructor, fecha);

    // Agregar ejercicios por categoría
    string categorias[] = { "Pecho", "Triceps", "Biceps", "Piernas", "Espalda" };

    for (int c = 0; c < 5; c++) {
        cout << "\n--- SELECCIONAR EJERCICIOS PARA " << categorias[c] << " ---" << endl;

        // Mostrar ejercicios disponibles de esta categoría
        int count = 0;
        Ejercicio* ejerciciosCategoria[100] = { nullptr };

        for (int i = 0; i < numEjercicios; i++) {
            if (bateriaEjercicios[i]->getArea() == categorias[c]) {
                cout << count + 1 << ". ";
                bateriaEjercicios[i]->mostrarInfoBasica();
                ejerciciosCategoria[count++] = bateriaEjercicios[i];
            }
        }

        if (count == 0) {
            cout << "No hay ejercicios disponibles para esta categoría." << endl;
            continue;
        }

        cout << "¿Cuantos ejercicios de " << categorias[c] << " desea agregar? (0-" << count << "): ";
        int cantidad;
        cin >> cantidad;

        if (cantidad > 0 && cantidad <= count) {
            for (int i = 0; i < cantidad; i++) {
                cout << "Seleccione el ejercicio " << i + 1 << " (1-" << count << "): ";
                int opcion;
                cin >> opcion;

                if (opcion >= 1 && opcion <= count) {
                    // Agregar ejercicio a la rutina según la categoría
                    if (categorias[c] == "Pecho") {
                        nuevaRutina->agregarEjercicioPecho(ejerciciosCategoria[opcion - 1]);
                    }
                    else if (categorias[c] == "Triceps") {
                        nuevaRutina->agregarEjercicioTriceps(ejerciciosCategoria[opcion - 1]);
                    }
                    else if (categorias[c] == "Biceps") {
                        nuevaRutina->agregarEjercicioBiceps(ejerciciosCategoria[opcion - 1]);
                    }
                    else if (categorias[c] == "Piernas") {
                        nuevaRutina->agregarEjercicioPiernas(ejerciciosCategoria[opcion - 1]);
                    }
                    else if (categorias[c] == "Espalda") {
                        nuevaRutina->agregarEjercicioEspalda(ejerciciosCategoria[opcion - 1]);
                    }
                    cout << "Ejercicio agregado: " << ejerciciosCategoria[opcion - 1]->getNombre() << endl;
                }
            }
        }
    }

    // Agregar rutina al sistema
    if (numRutinas >= capacidadRutinas) {
        capacidadRutinas *= 2;
        Rutina** nuevo = new Rutina * [capacidadRutinas];
        for (int i = 0; i < numRutinas; i++) {
            nuevo[i] = rutinaActual[i];
        }
        delete[] rutinaActual;
        rutinaActual = nuevo;
    }
    rutinaActual[numRutinas++] = nuevaRutina;

    cout << "\nRutina creada exitosamente!" << endl;
    nuevaRutina->ResumenRutina();
}

void Gimnasio::mostrarRutinaCliente() {
    if (numSucursales == 0) {
        cout << "No hay sucursales registradas." << endl;
        return;
    }

    Sucursal* sucursal = seleccionarSucursal();
    if (sucursal == nullptr) return;

    if (sucursal->getNumClientes() == 0) {
        cout << "No hay clientes en esta sucursal." << endl;
        return;
    }

    // Seleccionar cliente
    sucursal->listarClientes();
    cout << "Seleccione el numero del cliente: ";
    int opcionCliente;
    cin >> opcionCliente;

    Cliente** clientes = sucursal->obtenerClientes();
    if (opcionCliente < 1 || opcionCliente > sucursal->getNumClientes()) {
        cout << "Opcion invalida." << endl;
        return;
    }

    Cliente* cliente = clientes[opcionCliente - 1];

    // Buscar rutina del cliente
    Rutina* rutina = nullptr;
    for (int i = 0; i < numRutinas; i++) {
        if (rutinaActual[i]->getCliente()->getCedula() == cliente->getCedula()) {
            rutina = rutinaActual[i];
            break;
        }
    }

    if (rutina != nullptr) {
        rutina->mostrarRutina();
    }
    else {
        cout << "El cliente no tiene una rutina activa." << endl;
    }
}

void Gimnasio::listarRutinasActivas() const {
    cout << "\n=== RUTINAS ACTIVAS ===" << endl;
    cout << "Total de rutinas activas: " << numRutinas << endl;

    if (numRutinas == 0) {
        cout << "No hay rutinas activas en el sistema." << endl;
        return;
    }

    for (int i = 0; i < numRutinas; i++) {
        cout << "\n--- Rutina " << i + 1 << " ---" << endl;
        rutinaActual[i]->ResumenRutina();
    }
}

// ==================== GESTIÓN DE CLASES GRUPALES ====================
void Gimnasio::menuClasesGrupales(Sucursal* sucursal) {
    if (sucursal == nullptr) return;

    int opcion;
    do {
        cout << "\n--- CLASES GRUPALES - " << sucursal->getCodigo() << " ---" << endl;
        cout << "1. Crear Clase Grupal" << endl;
        cout << "2. Matricular Cliente" << endl;
        cout << "3. Desmatricular Cliente" << endl;
        cout << "4. Listar Clases" << endl;
        cout << "5. Volver" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
        case 1: agregarClaseGrupal(); break;
        case 2: matricularCliente(); break;
        case 3: sucursal->listarClasesGrupales(); break;
        case 4: break;
        default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 4);
}

void Gimnasio::agregarClaseGrupal() {
    if (numSucursales == 0) {
        cout << "No hay sucursales registradas." << endl;
        return;
    }

    Sucursal* sucursal = seleccionarSucursal();
    if (sucursal == nullptr) return;

    if (sucursal->getNumInstructores() == 0) {
        cout << "No hay instructores en esta sucursal." << endl;
        return;
    }

    // Verificar límite de clases
    if (sucursal->getNumClasesG() >= 8) {
        cout << "Límite alcanzado. Máximo 8 clases grupales por sucursal." << endl;
        return;
    }

    string codigo, especialidad, horario, salon;
    int cupoMax;

    cout << "\n--- CREAR CLASE GRUPAL ---" << endl;

    // Validar código único
    string codigoTemp;
    bool codigoValido = false;
    do {
        cout << "Codigo de clase (debe ser único): ";
        cin.ignore();
        getline(cin, codigoTemp);

        if (sucursal->buscarClaseGrupal(codigoTemp) != nullptr) {
            cout << "Error: Ya existe una clase con este código en la sucursal." << endl;
        }
        else {
            codigoValido = true;
            codigo = codigoTemp;
        }
    } while (!codigoValido);

    // Seleccionar tipo
    string tiposValidos[] = { "CrossFit", "HIIT", "TRX", "Pesas", "Spinning", "Cardio", "Yoga", "Zumba" };
    cout << "Tipos de clase disponibles:" << endl;
    for (int i = 0; i < 8; i++) {
        cout << i + 1 << ". " << tiposValidos[i] << endl;
    }
    cout << "Seleccione el tipo de clase (1-8): ";
    int opcionTipo;
    cin >> opcionTipo;

    if (opcionTipo < 1 || opcionTipo > 8) {
        cout << "Opción inválida. Se asignará CrossFit por defecto." << endl;
        especialidad = "CrossFit";
    }
    else {
        especialidad = tiposValidos[opcionTipo - 1];
    }

    cin.ignore();
    cout << "Salon: ";
    getline(cin, salon);
    cout << "Horario (ej: Lunes 16:00-17:00): ";
    getline(cin, horario);
    cout << "Cupo maximo: ";
    cin >> cupoMax;

    // Seleccionar instructor
    Instructor* instructorSeleccionado = nullptr;
    sucursal->listarInstructores();
    cout << "Seleccione el numero del instructor: ";
    int opcionInstructor;
    cin >> opcionInstructor;

    Instructor** instructores = sucursal->obtenerInstructores();
    if (opcionInstructor >= 1 && opcionInstructor <= sucursal->getNumInstructores()) {
        instructorSeleccionado = instructores[opcionInstructor - 1];
    }

    // Crear la clase grupal
    ClaseGrupal* nuevaClase = new ClaseGrupal(codigo, especialidad, horario, salon, cupoMax, instructorSeleccionado);
    sucursal->agregarClaseGrupal(nuevaClase);

    cout << "Clase grupal creada exitosamente!" << endl;
    nuevaClase->mostrarInfo();
}

void Gimnasio::matricularCliente() {
    if (numSucursales == 0) {
        cout << "No hay sucursales registradas." << endl;
        return;
    }

    Sucursal* sucursal = seleccionarSucursal();
    if (sucursal == nullptr) return;

    if (sucursal->getNumClasesG() == 0) {
        cout << "No hay clases grupales en esta sucursal." << endl;
        return;
    }

    if (sucursal->getNumClientes() == 0) {
        cout << "No hay clientes en esta sucursal." << endl;
        return;
    }

    // Listar clases
    sucursal->listarClasesGrupales();
    cout << "Seleccione el numero de la clase: ";
    int opcionClase;
    cin >> opcionClase;

    ClaseGrupal** clases = sucursal->obtenerClaseGrupal();
    if (opcionClase < 1 || opcionClase > sucursal->getNumClasesG()) {
        cout << "Opcion invalida." << endl;
        return;
    }

    ClaseGrupal* clase = clases[opcionClase - 1];

    if (clase->cuposDisponibles() <= 0) {
        cout << "Esta clase no tiene cupos disponibles." << endl;
        return;
    }

    // Mostrar clientes
    sucursal->listarClientes();
    cout << "Seleccione el numero del cliente a matricular: ";
    int opcionCliente;
    cin >> opcionCliente;

    Cliente** clientes = sucursal->obtenerClientes();
    if (opcionCliente < 1 || opcionCliente > sucursal->getNumClientes()) {
        cout << "Opcion invalida." << endl;
        return;
    }

    Cliente* cliente = clientes[opcionCliente - 1];

    // Matricular cliente
    if (clase->matricularCliente(cliente)) {
        cout << "Cliente matriculado exitosamente en la clase!" << endl;
        cout << "Cupos disponibles: " << clase->cuposDisponibles() << endl;
    }
    else {
        cout << "Error al matricular el cliente." << endl;
    }
}

void Gimnasio::listarClasesGrupales() const {
    cout << "\n=== CLASES GRUPALES POR SUCURSAL ===" << endl;

    if (numSucursales == 0) {
        cout << "No hay sucursales registradas." << endl;
        return;
    }

    for (int i = 0; i < numSucursales; i++) {
        cout << "\n--- Sucursal: " << sucursales[i]->getCodigo() << " ---" << endl;
        sucursales[i]->listarClasesGrupales();
    }
}

void Gimnasio::mostrarMenuPrincipal() const {
    cout << "\n==========================================" << endl;
    cout << "             POWERLAB GYM" << endl;
    cout << "==========================================" << endl;
    cout << "Sucursales: " << numSucursales << " | Clientes: " << numSucursales * 3 << " | Ejercicios: " << numEjercicios << endl;
    cout << "1. Gestionar Sucursales" << endl;
    cout << "2. Gestionar Mediciones" << endl;
    cout << "3. Bateria de Ejercicios" << endl;
    cout << "4. Gestionar Rutinas" << endl;
    cout << "5. Clases Grupales" << endl;
    cout << "6. Reportes y Consultas" << endl;
    cout << "7. Salir" << endl;
    cout << "==========================================" << endl;
    cout << "Seleccione una opcion: ";
}

void Gimnasio::ejecutar() {
    int opcion;
    do {
        mostrarMenuPrincipal();
        cin >> opcion;

        switch (opcion) {
        case 1: {
            int subopcion;
            cout << "\n--- GESTION DE SUCURSALES ---" << endl;
            cout << "1. Agregar Sucursal" << endl;
            cout << "2. Listar Sucursales" << endl;
            cout << "3. Gestionar Sucursal Especifica" << endl;
            cout << "4. Volver" << endl;
            cout << "Seleccione: ";
            cin >> subopcion;

            switch (subopcion) {
            case 1: agregarSucursal(); break;
            case 2: listarSucursales(); break;
            case 3: gestionarSucursal(); break;
            case 4: break;
            default: cout << "Opcion invalida." << endl;
            }
            break;
        }
        case 2: menuMediciones(); break;
        case 3: menuBateriaEjercicios(); break;
        case 4: menuRutinas(); break;
        case 5: {
            Sucursal* sucursal = seleccionarSucursal();
            if (sucursal) menuClasesGrupales(sucursal);
            break;
        }
        case 6: {
            cout << "\n--- REPORTES Y CONSULTAS ---" << endl;
            cout << "1. Listar Rutinas Activas" << endl;
            cout << "2. Listar Clases Grupales" << endl;
            cout << "3. Volver" << endl;
            cout << "Seleccione: ";
            int subop;
            cin >> subop;
            switch (subop) {
            case 1: listarRutinasActivas(); break;
            case 2: listarClasesGrupales(); break;
            }
            break;
        }
        case 7: cout << "Saliendo del sistema..." << endl; break;
        default: cout << "Opcion invalida." << endl;
        }
    } while (opcion != 7);
}