#include <iostream>

using namespace std;

int main()
{	
	int hora_inicio, hora_fim, min_inicio, min_fim, horas, minutos;
	cin >> hora_inicio >> min_inicio >> hora_fim >> min_fim;
	if (hora_fim == 0) 
		hora_fim = 24;
	horas = (hora_fim - hora_inicio)*60;
	minutos = (min_fim - min_inicio);
	minutos = (horas + minutos);
	horas = minutos/60;
	minutos = minutos%60;
	if (horas < 0)
		horas = horas*(-1);
	if (minutos < 0)
		minutos = minutos*(-1);
	if ((hora_inicio == hora_fim) && (min_inicio == min_fim))
		horas = 24;
	cout << "O JOGO DUROU " << horas << " HORA(S) E " << minutos << " MINUTO(S)" << endl;
	return 0;
}