
# Fractol

Fractol est un programme de visualisation de fractales développé en C utilisant la bibliothèque graphique MiniLibX. Il permet d'explorer des ensembles fractals célèbres avec des fonctionnalités interactives.

![Fractale](https://github.com/Itraya/fractol/blob/main/screenshots/Fractale.png?raw=true)


## Features

- Génération et affichage de fractales célèbres :
    - Ensemble de Mandelbrot
    - Ensemble de Julia
    - Fractale Burning Ship

- Navigation et zoom interactifs

- Support de palettes de couleurs pour un rendu visuel amélioré
## Installation

### Prérequis

- Un système macOS

### Compilation

```bash
git clone https://github.com/ton-utilisateur/fractol.git
cd fractol
make
```

## Utilisation

```bash
./fractol mandelbrot
./fractol julia
./fractol burning_ship
```
Des interactions sont possibles via le clavier et la souris :

    -Flèches directionnelles : déplacer la vue
    -Position de la souris : paramètres pour l'ensemble de Julia
    -Molette de la souris : zoomer/dézoomer
    -Touches 1-8 : modifier les palettes de couleurs
    -Échap : quitter le programme
    
<br>

![Fractale2](https://github.com/Itraya/fractol/blob/main/screenshots/Fractale2.png?raw=true)


