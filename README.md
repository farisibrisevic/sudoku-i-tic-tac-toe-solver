<h1 align = "center"> Projekat iz predmeta "Napredne tehnike programiranja"</h1>
<h1 align = "center"> Tema: Sudoku i tic-tac-toe solver</h1>

<p>Projekat se bazira na pisanju algoritma za rješavanje popularnih igara kao što su tic-tac-toe (iks-oks) i sudoku. <br>
Projekat je pisan u C++ programskom jeziku. IDE koji je korišten je MS Visual Studio. </p>

<p><i>Profesor: </i> prof. dr. Nevzudin Buzađija</p>

<p><i>Asistenti: </i> Edin Tabak</p>

<i>Asistenti: </i> Narcisa Hadžajlić</p>
<hr>

<b>12.04.2023. </b> - Dodana kruto napravljena igrica "tic-tac-toe" tako da korisnik, ili korisnici, unose svoje simbole u određena polja. Polja su prikazana brojevima od 1 do 9.
<br>

"Tabla" izgleda ovako: 

1 2 3 

4 5 6

7 8 9

Program traži od korisnika unosom broja da odredi polje. Ako je korisnik unio 5, u sljedećem prikazu tabla ne izgleda kao iznad nego ovako: 

1 2 3

4 X 6

7 8 9

Program se izvršava sve dok se ne desi jedan od tri moguća ishoda: X pobjednik, O pobjednik ili neriješeno. 

10.05.2023. - Promijenjeno ime fajla, radi lakše organizacije. Kod, način na koji radi, te sistem je ostao isti. Nikakve promjene nisu vršene u kodu, osim promjene imena.

<br>
<hr>
Nakon skoro mjesec dana (10.05.2023.) dodan je sudoku. Ovaj fajl se zasniva na sličnom principu kao prethodno opisani fajl, samo što je ovaj put sudoku u pitanju. Korisnik unosi red, kolonu i vrijednost, prateći pravila igre. Ako unese broj koji je već unutar te tabele, "igra" će od njega zatražiti da unese ponovo, ne govoreći gdje je greška. To će raditi, sve dok korisnik ne unese pravilan broj. Kada se ispuni čitava ploča, korisnik dobija jednu od dvije poruke, uspješno ili neuspješno riješeno. Ploča se ispunjava nasumičnim brojevima, a ona prazna predstavljena su nulom. 
Izgled tabele:

![image](https://github.com/farisibrisevic/sudoku-i-tic-tac-toe-solver/assets/115661874/8534a407-5a25-45c0-a8c5-d9360e1806e2)


Brojevi iznad označavaju broj kolone, a brojevi s lijeve strane označavaju broj reda. 

<br>
<hr>

22.05.2023. - Dodan je tic-tac-toe solver. Naime, solver nije solver, nego klasični player vs računar sistem. Kada igrač napravi potez, računar napravi potez, sukladno potezu igrača. Radi manjka i neznanja pravljenja funkcionalnih interfejsa, lahko je pogriješiti. 

<br>
04.06.2023. - Dodan je fajl sudoku-solver. Ovaj fajl je generator i rješavač Sudokua. Kada korisnik pokrene ovaj fajl, generiše se slučajno generisana Sudoku tabla sa rješenjem. Zbog nedostatka znanja iz programairanja u C++, trenutna verzija ovog fajla ne omogućava korisniku izbor tabela ili težine igre, već samo generiše jednu random tablu
