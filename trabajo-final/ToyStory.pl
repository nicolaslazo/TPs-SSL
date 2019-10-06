dueño(andy, woody, 8).
dueño(sam, jessie, 3).

deTrapo(tematica).
deAccion(tematica, partes).
miniFiguras(tematica, cantidadDeFiguras).
caraDePapa(partes).

juguete(woody, deTrapo(vaquero)).
juguete(jessie, deTrapo(vaquero))
juguete(buzz, deAccion(espacial, [original(casco)]).
juguete(soldados, miniFiguras(soldado, 60)).
juguete(monitosEnBarril, miniFiguras(mono, 50)).
juguete(señorCaraDePapa, caraDePapa([ original(pieIzquierdo),original(pieDerecho),repuesto(nariz) ])).

esRaro(deAccion(stacyMalibu, 1, [sombrero])).

esColeccionista(sam).

tematica(UnJuguete, TematicaDelJuguete):-
	
	lasTematicasDelJuguete(TematicaDelJuguete).
	
lasTematicasDelJuguete(deTrapo(TematicaDelJuguete)).
lasTematicasDelJuguete(deAccion(TematicaDelJuguete, listaDePartes)).
lasTematicasDelJuguete(miniFiguras(TematicaDelJuguete, cantidadDeFiguras)).
lasTematicasDelJuguete(caraDePapa(listaDePartes)).


