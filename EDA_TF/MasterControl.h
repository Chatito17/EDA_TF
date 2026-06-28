#pragma once
#include <iostream>
#include "ItemControl.h"
#include "NotificacionControl.h"
#include "UsuarioControl.h"

class MasterControl
{
private:
	ItemControl* itemControl;
	NotificacionControl* notificacionControl;
	UsuarioControl* usuarioControl;

public:
	MasterControl() : itemControl(new ItemControl()), notificacionControl(new NotificacionControl()), usuarioControl(new UsuarioControl()){}
	~MasterControl(){
		delete itemControl;
		delete notificacionControl;
		delete usuarioControl;
	}

	void menu() {
		int opc = 0;
		do {
			std::cout << "\n=== MENU MASTER ===";
			std::cout << "\n1. Modulo de Usuarios.";
			std::cout << "\n2. Modulo de Preguntas.";
			std::cout << "\n3. Modulo de Items.";
			std::cout << "\n4. Modulo de Notificaciones.";
			std::cout << "\n5. Salir.";
			std::cout << "\n\nDigite la opcion: "; cin >> opc;

			if (opc == 1) {
				moduloUsuario();
			}
			else if (opc == 2) {
				std::cout << "\nhomo\n";
			}
			else if (opc == 3) {
				moduloItem();
			}
			else if (opc == 4) {
				moduloNotificacion();
			}
			else if (opc == 5) {
				std::cout << std::endl << "Hasta luego! :D" << std::endl;
			}
		} while (opc != 5);
	}

	void moduloItem() {
		itemControl->menu();
	}
	void moduloNotificacion() {
		notificacionControl->menu();
	}
	void moduloUsuario() {
		usuarioControl->menu();
	}
};
