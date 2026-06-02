# Mini System Bankowy

Projekt zrealizowany w ramach zadania rekrutacyjnego na staż w CGI Programista C++. 

## O projekcie
Jest to prosta aplikacja symulująca system bankowy. Zgodnie z wytycznymi, podstawowa logika biznesowa została napisana w C++, natomiast podstawowy UI zrealizowano przy pomocy frameworka Qt. 

Program nie korzysta z zewnętrznej bazy danych – stan kont i inofrmacje o nich są przechowywane w wektorze w pamięci operacyjnej tylko podczas działania aplikacji.

### Główne funkcjonalności
* Tworzenie nowego konta bankowego
* Wpłata środków na wskazane konto
* Wypłata środków z blokadą zapobiegającą powstawaniu debetu
* Wyświetlanie informacji o stanie konta oraz historii bieżących operacji w oknie logów

## Struktura projektu i kompilacja
Projekt bazuje na standardzie C++17 i został przygotowany w środowisku Visual Studio 2022 przy użyciu rozszerzenia Qt Visual Studio Tools. 

Kod został podzielony na:
* `include/` – pliki nagłówkowe (`.h`)
* `src/` – pliki źródłowe (`.cpp`) z podziałem na logikę bankową (`BankAccount`) oraz interfejs okienkowy (`MainWindow`).

## Komendy Git
Zgodnie z poleceniem w zadaniu, poniżej zestawienie podstawowych komend użytych do stworzenia i wypchnięcia tego repozytorium:

```bash
# 1. Inicjalizacja lokalnego repozytorium w folderze projektu
git init

# 2. Dodanie plików projektu do śledzenia, dzięki .gitignore pomijane są pliki binarne i konfiguracyjne IDE
git add .

# 3. Zatwierdzenie zmian z odpowiednią wiadomością
git commit -m "Feat: Spięcie logiki z GUI i konfiguracja punktu wejścia programu"

# 4. Połączenie lokalnego repozytorium z utworzonym repozytorium na GitHubie
git remote add origin [https://github.com/TwojaNazwaUzytkownika/MiniSystemBankowy.git](https://github.com/TwojaNazwaUzytkownika/MiniSystemBankowy.git)

# 5. Wypchnięcie zmian na serwer do gałęzi master/main
git push -u origin master
