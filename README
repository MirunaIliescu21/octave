Copyright Miruna-elena Iliescu 312CAb 2023-2024

INCARCAREA UNEI MATRICI IN MEMORIE:
Citesc nr linii, nr coloane si aloc memorie pt citirea unui matrici de aceasta
dimensiuni, urmand sa o citesc de la tastatura prin functia read_matrix.
Folosesc un resizable array care reprezinta colectia de matrici.
Pe fiecare pozitie a acestui vector se va afla o noua matrice citita,
avand dimensiunile retinute in cate un vector, ql pt nr de linii si
qc pt nr de coloane.
Inainte de adauga o noua matrice in colectie prin functia  add_matrix, 
trebuie sa verific daca colectia si cei doi vectori au capacitatea necesara
pt a mai adauga elemente, in cazul in care capacitatea este egala cu nr de 
matrici deja adaugate, dublez capacitatea atat a colectiei de matrici, 
cat si a vectorilor prin functia realloc.

DETERMINAREA DIMENSIUNILOR UNEI MATRICI:
Citesc un index si verific daca exista matrice in colectie pe pozitia
respectiva. In cazul in care indexul este valid afisez valorile de pe pozitia
citita din vectorii ql, qc, iar in caz contra, afisez un mesaj de eroare.

AFISAREA UNUI MATRICI DIN COLECTIE:
Citesc un index si verific daca exista matrice in colectie pe pozitia
respectiva. In cazul in care indexul este valid afisez matricea de pe pozitia
citita din colectie, iar in caz contra, afisez un mesaj de eroare.

REDIMENSIONAREA UNEI MATRICI:
Citesc indexul matriciei, un nr de linii egal noul nr de linii al matriciei
redimensionate, urmat de indexi linilor ce raman in noua matrice si un nr de
coloane egal cu noul nr de coloane al matriciei redimensionate, urmat de indexi
coloanelor ce raman in noua matrice. In cazul in care indexul este valid fac
operatia de redimensionarece ce presupune pastrarea elementelor de pe pozitiile
citite si se creeaza o noua matrice, alocandu-i memorie conform dimensunilor
citite. Aceasta matrice nou formata va inlocui vechea matrice pe aceeasi
pozitie in colectie, iar in caz in care pe indexul introdus initial este
invalid, afisez un mesaj de eroare.

INMULTIREA A DOUA MATRICI:
Citesc doi indexi a caror matrici urmeaza sa fie inmultite.
Daca exista matrici in colectie pe acele pozitii, verific daca dimensiunile
sale sunt corespunzatoare pentru a efectua inmultirea (numarul de coloane
al primei matrici este egal cu numarul de linii al celei de a doua matrici).
Altfel, afisez mesaje de eroare corespunzatoare.
Algoritmul pentru inmultire consta in implementarea unei functii ce extrage
fiecare linii din prima matrice, adaugand-o intr-un vector si a unei functii
ce extrage fiecare coloana din a doua matrice, adaugand-o intr-un alt vector,
urmand sa se faca o suma constituita din inmultirea element cu element
a celor doi vectori.
Se aloca memorie pentru matricea rezultat si se adauga la finalul colectie.
De asemenea, atunci cand adaug o noua matrice in colectie trebuie sa verific
capacitatea colectiei si a vectorilor de linii, respectiv coloane, la fel
cum am facut la "incarcarea unei matrici in memorie".

SORTAREA MATRICELOR:
Calculez suma elementelor fiecarei matrici din colectie in vectorul sum, 
iar in vectorul top se pune indexul matricilor astfel incat sa rezulte o lista
ordonata crescator a indexilor initiali ai matricilor in functie de suma
elementelor sale. Creerea vectorului top presupune parcurgerea vectorului
sum pentru a vedea pozitia matricelor din colectia initiala, nesortata.
Sortarea crescatoarea este implementata cu ajutorul algoritmului Radix Sort.

TRANSPUNEREA UNEI MATRICI:
Citesc un index si verific daca exista matrice in colectie pe pozitia
respectiva. Pentru a transpune o matrice folosesc spatiu de memorie comun 
alocat matriciei initiale. Toate liniile care se pastreaza se redimensioneaza
si ori se aloca memorie pentru liniile suplimentare ori se elibereaza liniile
neutilizate. Matricea transpusa se inlocuieste in colectie.

ELIBERAREA MEMORIEI UNEI MATRICI:
Citesc un index si verific daca exista matrice in colectie pe pozitia
respectiva. Daca exista, copiez intr-o noua colectie toate matricile
care au indexul diferit de cel citit, altfel, afisez un mesaj de eroare.

ELIBIRAREA TUTUROR RESURSELOR:
Se parcurge fiecare matrice din colectie si se apeleaza functia care elibereaza
memoria fiecarui vector de linii din aceste matrici. Urmeaza sa se elibereze si
pointerii catre vectorii de linii, apoi se elibereaza pointerul catre colectie.

INMULTIREA MATRICELOR FOLOSIND ALGORITMUL LUI STRASSEN:
Citesc doi indexi a caror matrici urmeaza sa fie inmultite.
Daca exista matrici in colectie pe acele pozitii, verific daca 
sunt patratice, altfel afisez mesaje de eroare.
Algoritmul Strassen presupune descompunerea in blocuri de matrici pana
se ajunge la matrici de dimensiunea 1x1. 
Impart cele doua matrice din colectie în patru submatrici, le aloc
memorie si le initializez cu valori din matricele initiale.
Se calculeaza valorile a 7 matrici ce reprezinta produce intermediare
a submatricilor initializate anterior (aceste operatii se regasesc in cod, 
sub forma unor comentarii). 
Se aduna aceste produse intermediare  si se copiaza in matricea rezultat.
Este necesar sa eliberam toata memoria alocata acestor matrici. 


