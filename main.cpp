#include <SFML/Graphics.hpp>

#include <windows.h>

#include <iostream>

#include <ctime>

#include <cmath>

using namespace sf;
using namespace std;
int main() {

  //Varijabla koja ce regulisati boju
  int boja = 1;

  //Varijabla koja prati da li je prvi ili drugi klik

  int i = 0;
  int daljina = 0;
  int l = 0;
  float ugao;
  int woo = 0;
  //Varijable za unosenje teksta
  String playerInput;
  Text playerText;
  //Linije
  RectangleShape linije[50];
  RectangleShape shadowLine;
  //Varijable koje ce nam govoriti koordinate
  Vector2i pozicija1;
  Vector2i pozicija2;
  int skrn = 0;
  //Deklarisanje brojaca
  int g = 0;
  Event event;
  Event gevent;
  Vector2i pozi;
  //tekstura pozadina glavna
  Texture gpozadinskaTekstura;
  gpozadinskaTekstura.loadFromFile("res/glavniProzor.png");
  Sprite gpozadinaSprite;
  gpozadinaSprite.setTexture(gpozadinskaTekstura);
  // Pravljenje glavnog prozora

  RenderWindow gwindow(VideoMode(600, 600), "Paint Factory");
  gwindow.clear();
  gwindow.setFramerateLimit(10);
  Vector2i w_Pos = gwindow.getPosition();
  gwindow.setPosition(Vector2i(-111110, -111110));
  gwindow.clear();

  gwindow.setPosition(w_Pos);
  gwindow.draw(gpozadinaSprite);
  gwindow.display();

  Image ikona;
  ikona.loadFromFile("res/PaintLogo565.png");

  gwindow.setIcon(ikona.getSize().x, ikona.getSize().y, ikona.getPixelsPtr());
  //Deklarisanje save tipke
  Texture save;
  Texture pritisnutiSave;
  save.loadFromFile("res/save.png");
  pritisnutiSave.loadFromFile("res/saveClicked.png");
  Sprite saveSprite;
  saveSprite.setTexture(save);
  saveSprite.setPosition(622, 2);
  //Deklarisanje undo
  Texture undo;
  Texture pritisnutiUndo;
  undo.loadFromFile("res/undo.png");
  pritisnutiUndo.loadFromFile("res/undoClicked.png");
  Sprite undoSprite;
  undoSprite.setTexture(undo);
  undoSprite.setPosition(526, 2);

  //Deklarisanje kante
  Texture kanta;
  Texture pritisnutaKanta;
  kanta.loadFromFile("res/trash.png");
  pritisnutaKanta.loadFromFile("res/trashClicked.png");
  Sprite kantaSprite;
  kantaSprite.setTexture(kanta);
  kantaSprite.setPosition(700, -1);
  //tekstura za spremanje slike

  //Deklarisanje pozadine
  Texture pozadinskaTekstura;
  pozadinskaTekstura.loadFromFile("res/pozadina.png");
  Sprite pozadinaSprite;
  pozadinaSprite.setTexture(pozadinskaTekstura);

  //Deklarisanje toolkita
  Texture toolkitTekstura;
  toolkitTekstura.loadFromFile("res/toolkit1.png");
  Sprite toolkitSprite;
  toolkitSprite.setTexture(toolkitTekstura);

  //Deklarisanje alata
  Texture alatiTekstura;
  alatiTekstura.loadFromFile("res/alati1.png");
  Sprite alati;
  alati.setTexture(alatiTekstura);

  //Deklarisanje toolkita
  Texture sizeChanger;
  sizeChanger.loadFromFile("res/sizeChanger1.png");
  Sprite changerSprite;
  changerSprite.setTexture(sizeChanger);
  //Deklarisanje niza pravougaonika
  RectangleShape kocke[50];
  RectangleShape shadow;
  CircleShape krug[50];
  CircleShape circleShadow;
  int isShadow = 0;
  int circleSize = 5;
  int alat = 1;
  while (gwindow.isOpen()) {
    gwindow.draw(gpozadinaSprite);

    while (gwindow.pollEvent(gevent)) {
      if (Mouse::isButtonPressed(Mouse::Left)) {
        pozi = Mouse::getPosition(gwindow);
        if (pozi.x > 381 && pozi.x < 560 && pozi.y > 549 && pozi.y < 585) {
          gwindow.close();
        }
      }
      // Izlazenje iz prozora
      if (gevent.type == sf::Event::Closed) {
        gwindow.close();
        woo = 1;
      }
    }

    gwindow.display();
  }
  if (woo != 1) {
    RenderWindow window(VideoMode(800, 500), "PaintFactory");
    window.clear();
    w_Pos = window.getPosition();

    window.setPosition(Vector2i(-111110, -111110));
    window.clear();
    window.setPosition(w_Pos);
    window.setIcon(ikona.getSize().x, ikona.getSize().y, ikona.getPixelsPtr());
    window.setFramerateLimit(30);
    Texture t;
    t.create(window.getSize().x, window.getSize().y);
    window.draw(pozadinaSprite);
    window.display();
    // Zapocni ciklicku strukturu igre
    while (window.isOpen()) {

      window.clear();

      window.draw(pozadinaSprite);

      while (window.pollEvent(event)) {
        if (Mouse::isButtonPressed(Mouse::Left)) {

          kantaSprite.setTexture(kanta);
          undoSprite.setTexture(undo);
          saveSprite.setTexture(save);
          pozi = Mouse::getPosition(window);

          if (g >= 50) {
            g = 0;
          }
          if (pozi.x > 775 && pozi.x < 795 && pozi.y > 223 && pozi.y < 298) {
            if (pozi.y > 223 && pozi.y < 243) {
              alatiTekstura.loadFromFile("res/alati1.png");
              alati.setTexture(alatiTekstura);
              alat = 1;
              isShadow = 0;
            } else if (pozi.y > 253 && pozi.y < 270) {
              alatiTekstura.loadFromFile("res/alati2.png");
              alati.setTexture(alatiTekstura);
              alat = 2;
              isShadow = 0;

            } else if (pozi.y > 280 && pozi.y < 297) {
              alatiTekstura.loadFromFile("res/alati3.png");
              alati.setTexture(alatiTekstura);
              alat = 3;
              isShadow = 3;
            }

          } else if (pozi.x > 0 && pozi.x < 26 && pozi.y > 126 && pozi.y < 426) {
            if (pozi.y > 139 && pozi.y < 163) {
              sizeChanger.loadFromFile("res/sizeChanger1.png");
              changerSprite.setTexture(sizeChanger);
              circleSize = 5;
            } else if (pozi.y > 173 && pozi.y < 198) {
              sizeChanger.loadFromFile("res/sizeChanger2.png");
              changerSprite.setTexture(sizeChanger);
              circleSize = 10;
            } else if (pozi.y > 213 && pozi.y < 237) {
              sizeChanger.loadFromFile("res/sizeChanger3.png");
              changerSprite.setTexture(sizeChanger);
              circleSize = 20;
            } else if (pozi.y > 248 && pozi.y < 272) {
              sizeChanger.loadFromFile("res/sizeChanger4.png");
              changerSprite.setTexture(sizeChanger);
              circleSize = 30;
            } else if (pozi.y > 282 && pozi.y < 309) {
              sizeChanger.loadFromFile("res/sizeChanger5.png");
              changerSprite.setTexture(sizeChanger);
              circleSize = 40;
            } else if (pozi.y > 320 && pozi.y < 345) {
              sizeChanger.loadFromFile("res/sizeChanger6.png");
              changerSprite.setTexture(sizeChanger);
              circleSize = 50;
            } else if (pozi.y > 357 && pozi.y < 381) {
              sizeChanger.loadFromFile("res/sizeChanger7.png");
              changerSprite.setTexture(sizeChanger);
              circleSize = 100;
            } else if (pozi.y > 394 && pozi.y < 416) {
              sizeChanger.loadFromFile("res/sizeChanger8.png");
              changerSprite.setTexture(sizeChanger);
              circleSize = 150;
            }
            if (isShadow == 3) {} else
              isShadow = 0;
          } else if (pozi.x > 525 && pozi.x < 605 && pozi.y > 2 && pozi.y < 58) {
            i = 0;
            undoSprite.setTexture(pritisnutiUndo);
            if (g > 0) {
              g--;
              kocke[g].setSize(Vector2f(0, 0));
              linije[g].setSize(Vector2f(0, 0));
              krug[g].setRadius(0);
            }
            if (isShadow == 3) {} else
              isShadow = 0;
          } else if (pozi.x > 700 && pozi.x < 800 && pozi.y > 0 && pozi.y < 50) {
            if (isShadow == 3) {} else
              isShadow = 0;
            //Spasavanje screenshota
            kantaSprite.setTexture(pritisnutaKanta);
            for (int v = 0; v < g; v++) {
              kocke[v].setSize(Vector2f(0, 0));
              linije[v].setSize(Vector2f(0, 0));
              krug[v].setRadius(0);
            }
            g = 0;
            i = 0;

          } else if (pozi.x > 622 && pozi.x < 694 && pozi.y > 2 && pozi.y < 62) {
            saveSprite.setTexture(pritisnutiSave);
            skrn = 10;
            i = 0;
            if (isShadow == 3) {} else
              isShadow = 0;
          } else if (pozi.x > 55 && pozi.x < 735 && pozi.y > 465 && pozi.y < 500) {
            if (pozi.x > 66 && pozi.x < 94 && pozi.y > 470 && pozi.y < 500) {
              boja = 1;
              toolkitTekstura.loadFromFile("res/toolkit1.png");
            } else if (pozi.x > 105 && pozi.x < 136 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit2.png");
              boja = 2;
            } else if (pozi.x > 145 && pozi.x < 175 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit3.png");
              boja = 3;
            } else if (pozi.x > 185 && pozi.x < 216 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit4.png");
              boja = 4;
            } else if (pozi.x > 226 && pozi.x < 255 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit5.png");
              boja = 5;
            } else if (pozi.x > 266 && pozi.x < 294 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit6.png");
              boja = 6;
            } else if (pozi.x > 305 && pozi.x < 335 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit7.png");
              boja = 7;
            } else if (pozi.x > 345 && pozi.x < 376 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit8.png");
              boja = 8;
            } else if (pozi.x > 385 && pozi.x < 414 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit9.png");
              boja = 9;
            } else if (pozi.x > 423 && pozi.x < 453 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit10.png");
              boja = 10;
            } else if (pozi.x > 465 && pozi.x < 493 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit12.png");
              boja = 11;
            } else if (pozi.x > 503 && pozi.x < 532 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit13.png");
              boja = 12;
            } else if (pozi.x > 545 && pozi.x < 571 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit14.png");
              boja = 13;
            } else if (pozi.x > 586 && pozi.x < 613 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit15.png");
              boja = 14;
            } else if (pozi.x > 625 && pozi.x < 652 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit16.png");
              boja = 15;
            } else if (pozi.x > 665 && pozi.x < 691 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit17.png");
              boja = 16;
            } else if (pozi.x > 704 && pozi.x < 731 && pozi.y > 470 && pozi.y < 500) {
              toolkitTekstura.loadFromFile("res/toolkit18.png");
              boja = 17;
            }
            i = 0;
            if (isShadow == 3) {} else
              isShadow = 0;
          } else {
            if (alat == 1) {
              if (i == 0) {
                pozicija1 = Mouse::getPosition(window);
                i = 1;
                isShadow = 1;
              } else if (i == 1) {
                kocke[g].setOutlineColor(Color(41, 41, 41));
                kocke[g].setOutlineThickness(5);
                isShadow = 0;
                pozicija2 = Mouse::getPosition(window);

                i = 0;

                switch (boja) {
                case 1:
                  kocke[g].setFillColor(Color(255, 24, 24));
                  break;
                case 2:
                  kocke[g].setFillColor(Color(169, 77, 148));
                  break;
                case 3:
                  kocke[g].setFillColor(Color(18, 105, 224));
                  break;
                case 4:
                  kocke[g].setFillColor(Color(206, 222, 20));
                  break;
                case 5:
                  kocke[g].setFillColor(Color(227, 118, 11));
                  break;
                case 6:
                  kocke[g].setFillColor(Color(49, 222, 20));
                  break;
                case 7:
                  kocke[g].setFillColor(Color(22, 128, 4));
                  break;
                case 8:
                  kocke[g].setFillColor(Color(29, 61, 179));
                  break;
                case 9:
                  kocke[g].setFillColor(Color(14, 166, 136));
                  break;
                case 10:
                  kocke[g].setFillColor(Color(7, 97, 79));
                  break;
                case 11:
                  kocke[g].setFillColor(Color(194, 3, 3));
                  break;
                case 12:
                  kocke[g].setFillColor(Color(232, 25, 210));
                  break;
                case 13:
                  kocke[g].setFillColor(Color(109, 56, 106));
                  break;
                case 14:
                  kocke[g].setFillColor(Color(105, 181, 31));
                  break;
                case 15:
                  kocke[g].setFillColor(Color(137, 137, 137));
                  break;
                case 16:
                  kocke[g].setFillColor(Color(225, 225, 225));
                  break;
                case 17:
                  kocke[g].setFillColor(Color(0, 0, 0));
                  break;
                }
                kocke[g].setPosition(Vector2f(pozicija1.x, pozicija1.y));
                kocke[g].setSize(Vector2f(pozicija2.x - pozicija1.x, pozicija2.y - pozicija1.y));

                g++;
              }
            } else if (alat == 2) {
              kantaSprite.setTexture(kanta);
              saveSprite.setTexture(save);
              undoSprite.setTexture(undo);

              if (g >= 50) {
                g = 0;
              }
              if (l == 0) {
                pozicija1 = Mouse::getPosition(window);
                l = 1;
                isShadow = 2;
              } else if (l == 1) {
                isShadow = 0;
                pozicija2 = Mouse::getPosition(window);
                ugao = atan2(pozicija2.y - pozicija1.y, pozicija2.x - pozicija1.x);
                linije[g].rotate(0);
                linije[g].setRotation(ugao * 180 / 3.14);
                linije[g].setPosition(Vector2f(pozicija1.x, pozicija1.y));
                linije[g].setSize(Vector2f(pozicija2.x - pozicija1.x, 5));
                daljina = sqrt((pozicija2.x - pozicija1.x) * (pozicija2.x - pozicija1.x) + (pozicija2.y - pozicija1.y) * (pozicija2.y - pozicija1.y));
                l = 0;
                linije[g].setOutlineColor(Color(41, 41, 41));
                linije[g].setOutlineThickness(2);

                linije[g].setSize(Vector2f(daljina, 5));
                switch (boja) {
                case 1:
                  linije[g].setFillColor(Color(255, 24, 24));
                  break;
                case 2:
                  linije[g].setFillColor(Color(169, 77, 148));
                  break;
                case 3:
                  linije[g].setFillColor(Color(18, 105, 224));
                  break;
                case 4:
                  linije[g].setFillColor(Color(206, 222, 20));
                  break;
                case 5:
                  linije[g].setFillColor(Color(227, 118, 11));
                  break;
                case 6:
                  linije[g].setFillColor(Color(49, 222, 20));
                  break;
                case 7:
                  linije[g].setFillColor(Color(22, 128, 4));
                  break;
                case 8:
                  linije[g].setFillColor(Color(29, 61, 179));
                  break;
                case 9:
                  linije[g].setFillColor(Color(14, 166, 136));
                  break;
                case 10:
                  linije[g].setFillColor(Color(7, 97, 79));
                  break;
                case 11:
                  linije[g].setFillColor(Color(194, 3, 3));
                  break;
                case 12:
                  linije[g].setFillColor(Color(232, 25, 210));
                  break;
                case 13:
                  linije[g].setFillColor(Color(109, 56, 106));
                  break;
                case 14:
                  linije[g].setFillColor(Color(105, 181, 31));
                  break;
                case 15:
                  linije[g].setFillColor(Color(137, 137, 137));
                  break;
                case 16:
                  linije[g].setFillColor(Color(225, 225, 225));
                  break;
                case 17:
                  linije[g].setFillColor(Color(0, 0, 0));
                  break;
                }
                ugao = 0;
                g++;

              }
            } else {
              if (g >= 50) {
                g = 0;
              }

              pozicija1 = Mouse::getPosition(window);
              switch (boja) {
              case 1:
                krug[g].setFillColor(Color(255, 24, 24));
                break;
              case 2:
                krug[g].setFillColor(Color(169, 77, 148));
                break;
              case 3:
                krug[g].setFillColor(Color(18, 105, 224));
                break;
              case 4:
                krug[g].setFillColor(Color(206, 222, 20));
                break;
              case 5:
                krug[g].setFillColor(Color(227, 118, 11));
                break;
              case 6:
                krug[g].setFillColor(Color(49, 222, 20));
                break;
              case 7:
                krug[g].setFillColor(Color(22, 128, 4));
                break;
              case 8:
                krug[g].setFillColor(Color(29, 61, 179));
                break;
              case 9:
                krug[g].setFillColor(Color(14, 166, 136));
                break;
              case 10:
                krug[g].setFillColor(Color(7, 97, 79));
                break;
              case 11:
                krug[g].setFillColor(Color(194, 3, 3));
                break;
              case 12:
                krug[g].setFillColor(Color(232, 25, 210));
                break;
              case 13:
                krug[g].setFillColor(Color(109, 56, 106));
                break;
              case 14:
                krug[g].setFillColor(Color(105, 181, 31));
                break;
              case 15:
                krug[g].setFillColor(Color(137, 137, 137));
                break;
              case 16:
                krug[g].setFillColor(Color(225, 225, 225));
                break;
              case 17:
                krug[g].setFillColor(Color(0, 0, 0));
                break;
              }
              krug[g].setRadius(circleSize);
              krug[g].setPosition(Vector2f(pozicija1.x - circleSize, pozicija1.y - circleSize));
              krug[g].setOutlineColor(Color(41, 41, 41));
              krug[g].setOutlineThickness(2);
              g++;

            }
          }

        }

        if (isShadow != 0) {
          if (isShadow == 1) {
            pozicija2 = Mouse::getPosition(window);
            shadow.setPosition(Vector2f(pozicija1.x, pozicija1.y));
            shadow.setSize(Vector2f(pozicija2.x - pozicija1.x, pozicija2.y - pozicija1.y));
            shadow.setFillColor(Color::Transparent);
            shadow.setOutlineThickness(5);
            shadow.setOutlineColor(Color::White);
          } else if (isShadow == 2) {
            pozicija2 = Mouse::getPosition(window);
            ugao = atan2(pozicija2.y - pozicija1.y, pozicija2.x - pozicija1.x);
            shadowLine.rotate(0);
            shadowLine.setRotation(ugao * 180 / 3.14);
            shadowLine.setPosition(Vector2f(pozicija1.x, pozicija1.y));
            shadowLine.setSize(Vector2f(pozicija2.x - pozicija1.x, 5));
            daljina = sqrt((pozicija2.x - pozicija1.x) * (pozicija2.x - pozicija1.x) + (pozicija2.y - pozicija1.y) * (pozicija2.y - pozicija1.y));
            shadowLine.setFillColor(Color::Transparent);
            shadowLine.setOutlineColor(Color::White);
            shadowLine.setOutlineThickness(2);
            shadowLine.setSize(Vector2f(daljina, 5));
          } else if (isShadow == 3) {
            pozicija1 = Mouse::getPosition(window);
            circleShadow.setRadius(circleSize);
            circleShadow.setPosition(Vector2f(pozicija1.x - circleSize, pozicija1.y - circleSize));
            circleShadow.setFillColor(Color::Transparent);
            circleShadow.setOutlineColor(Color::White);
            circleShadow.setOutlineThickness(2);

          }
        }
        // Izlazenje iz prozora
        if (event.type == sf::Event::Closed)
          window.close();
      }

      // Ispisi pravougaonike

      for (int v = 0; v < g; v++) {
        window.draw(kocke[v]);
        window.draw(linije[v]);
        window.draw(krug[v]);
      }

      // Nacrtaj objekte
      if (skrn == 10) {
        t.update(window);
        t.copyToImage().saveToFile("scrn.jpg");
        skrn = 0;
      }
      if (isShadow == 1) {
        window.draw(shadow);
      } else if (isShadow == 2) {
        window.draw(shadowLine);
      } else if (isShadow == 3) {
        window.draw(circleShadow);
      }
      window.draw(toolkitSprite);
      window.draw(changerSprite);
      window.draw(kantaSprite);
      window.draw(undoSprite);
      window.draw(saveSprite);
      window.draw(alati);

      // Updejtuj prozor
      window.display();
    }
  }

  return EXIT_SUCCESS;
}