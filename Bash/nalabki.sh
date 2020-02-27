# Imie i nazwisko:Kacper Kolodynski
# Temat cwiczenia: Sprawozdanie ze skryptu wykonujacego operacje na plikach ze zdjeciami.
# Data:15.12.2018

# Opis wybranych elementow dotyczacych pracy z systemem X Window
# Uruchomienie kilku klientow
# Poruszanie sie miedzy pulpitami
# xclock -geometry 200 200 -dsiplay :0
# xclock -geometry -200 -200 -display :0
# xclock -geometry -300 300 display -fg blue -bg green
# xclock -geomtry 0 0 -display :0
# xeyes -geometry 350 -400
# Tetowanie roznych srodowisk graficznych

#!/bin/bash
echo "Podaj folder wejsciowy z ktorego chcesz skopiowac pliki"
read sciezka_we
cd $sciezka_we
echo "Podaj folder wyjsciowy do którego chcesz skopiować pliki"
read sciezka_wy
mkdir ../$sciezka_wy

#usuwanie spacji
for nazwa in *JPEG
do
echo $nazwa|tr " " "_" |xargs mv "$nazwa"
done

for nazwa in *PNG
do
echo $nazwa|tr " " "_" |xargs mv "$nazwa"
done

#kopiowanie
for nazwa in *JPEG
do
cp $nazwa ../$sciezka_wy/$nazwa
done

for nazwa in *PNG
do
cp $nazwa ../$sciezka_wy/$nazwa
done

#zmiana rozszerzenia
cd ../$sciezka_wy
for nazwa in *.JPEG
do 
mv $nazwa ${nazwa%.JPEG}.jpeg 
done

for nazwa in *.PNG
do 
mv $nazwa ${nazwa%.PNG}.png
done

#zmiana rozmiaru
for nazwa in *.jpeg 
do
mogrify -resize $1x$2\! $nazwa
done

for nazwa in *.png
do
mogrify -resize $1x$2\! $nazwa
done

cd ../$sciezka_we
#archiwizowanie
tar -czvf archiwum.tar ../$sciezka_wy

#Testy skryptow: Opis przebiegu z efektem wykonania
#Test 1.
#Pobranie 6 zdjec do katalogu z rozszerzeniami JPEG oraz PNG, ktore maja w swych nazwach spacje
#Uruchomienie skryptu oraz podanie wymiarow na ktore ma zostac zmieniony rozmiar zdjec
#Wybranie katalogu, z ktorego maja zostac wczytane zdjecia do skryptu
#Wybranie nazwy katalogu, w ktorym maja zostac stworzone zmienione pliki, w przypadku nie istniejacej, skrypt utworzy nowy katalog.
#Efekt:
# -Skrypt zmienia " " na "_" w nazwach plikow, nastepnie kopiuje je i zmienia roszerzenia na pisane malymi literami.
# -W wybranym katalogu wyjsciowym pojawiaja sie zmienione pliki w rozmiarach przez nas podanych,z roszerzeniami napisanymi malymi literami oraz ze znakami podkreslenia zamiast spacjami w nazwach.
# -Utworzone zostaje archiwum ze zmienionymi zdjeciami w pliku wejsciowym.

#Test 2.
#Pobranie 6 zdjec do katalogu z rozszerzeniami JPEG oraz PNG bez spacji w nazwach.
#Uruchomienie skryptu oraz podanie wymiarow na ktore ma zostac zmieniony rozmiar zdjec
#Wybranie katalogu, z ktorego maja zostac wczytane zdjecia do skryptu
#Wybranie nazwy katalogu, w ktorym maja zostac stworzone zmienione pliki, w przypadku nie istniejacej skrypt utworzy nowy katalog.
#Efekt:
# -Skrypt nie moze zmienic spacji na znak podkreslenia poniewaz nie ma w nazwach zdjec spacji,dlatego tez informuje nas ze "nazwa" i "nazwa"na ktora miala byc zmieniona nazwa to ten sam plik.
# -W wybranym katalogu wyjsciowym pojawiaja sie zmienione pliki w rozmiarach przez nas podanych,z roszerzeniami napisanymi malymi literami 
# -Utworzone zostaje archiwum ze zmienionymi zdjeciami w pliku wejsciowym.
 
#Test 3.
#Pobranie 6 zdjec do katalogu z rozszerzeniami jpeg oraz png bez spacji w nazwach.
#Uruchomienie skryptu oraz podanie wymiarow na ktore ma zostac zmieniony rozmiar zdjec
#Wybranie katalogu, z ktorego maja zostac wczytane zdjecia do skryptu
#Wybranie nazwy katalogu, ktory nie istnieje
#Efekt:
# -Skrypt tworzy nowy katalog w ktorym znajduja sie nie zmienione pliki
# -Plik zostaje nie zmieniony poniewaz skrypt mial na celu wykonanie opracji na rozszrzeniach JPEG/PNG.Z racji ze rozszerzenia obrazkow sa juz napisane malymi literami , to skrypt jedynie zmienia ich nazwe na podskreslenia zamiast spacji. 
# - Utworzone zostaje archiwum ze zmienionymi zdjeciami w pliku wejsciowym.

#Test 4.
#Pobranie 6 zdjec do katalogu z rozszerzeniami JPEG oraz PNG bez spacji w nazwach.
#Uruchomienie skryptu
#Wybranie katalogu, z ktorego maja zostac wczytane zdjecia do skryptu
#Wybranie nazwy katalogu, ktory nie istnieje
#Efekt:
# -Skrypt tworzy nowy katalog w ktorym znajduja sie zmienione pliki
# -Pliki zostaja zmienione poza rozmiarem poniewaz nie podalismy na jaki rozmiar powinny sie zmienic.
# -Utworzone zostaje archiwum ze zmienionymi zdjeciami w pliku wejsciowym.

#Wnioski: Skrypt dziala poprawnie. Zmienia rozmiar zdjec, zmienia nazwy w ktorych znajduja sie spacje na podkreslenia oraz tworzy katalog oraz archiwum z tak przeksztalconymi plikami




