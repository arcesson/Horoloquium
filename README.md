# Horologium

Horologium ist eine einfache Qt-Applikation, die es ermöglicht, die verbleibende Zeit in Klassen für Gruppen- oder Einzelarbeiten oder für sonstige Aktivitäten sehr einfach darzustellen. Dazu kann man einfach in die Zeile im unteren Bereich eine Zeit in Minuten oder in der Form "Minuten:Sekunden" eintippen. Diese wird dann nach drücken auf "Start" als Countdown gesetzt und fortan heruntergezählt, während sich das Feld je nach verbleibender Zeit färbt (viel = grün, Hälfte der Zeit = gelb etc.).

## English

Horologium is a simple Qt application that displays the remaining time for teamwork, single person working or other activities in classrooms in simple way. To do this just type in a time in minutes or in the form "minutes:seconds" and press "Start". The countdown will begin immediately and will be colored depending of the percentage of the time left (much time left = green, half time gone = yellow and so on).

Written in pure C++/Qt.

## Build && Install for Ubuntu

### Dependencies
Required:
- qt5-default
- qt5-qmake
- qtbase5-dev-tools

### Installation

```
qmake
make
sudo make install
```
