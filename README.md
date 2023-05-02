# so_long <img src="https://user-images.githubusercontent.com/101518532/235779896-b6c8680e-22e2-485c-ad04-88c1ce38c0a3.png" alt="Project note" width="50" height="37">

<div align="center">
<img src="https://user-images.githubusercontent.com/101518532/232920360-1a51d988-3b3f-4f54-b361-1b8a80a572a7.jpg" alt="Gameplay screenshot" width="200" height="150">
<p><em>This is Bonnie. She is my sister's little rabbit and the inspiration for this project. How adorable is she? 😍</em></p>
</div>

## Table of contents
* [Instructions](#instructions)
* [Project overview](#project-overview)
* [Bonus](#bonus)
* [What I learned](#what-i-learned)

## Instructions
### Compilation
To compile the mandatory part, simply go into the cloned repository and use the <code>make</code> command. Then, you can execute the program like this: <code>./so_long maps/</code> and add the map you want to try after the '/'. I suggest using the laby.ber map or creating your own, but do not forget the [map requirements](#map-requirements)!

Example:
```
./so_long maps/laby.ber
```
As for the bonus part, you can write <code>make bonus</code> into the terminal to compile and then execute as showed below. Note that you will need a map that contains an enemy, or you will get an error message.

Example:
```
./so_long_bonus maps/bonus_maps/bonus_emptier.ber
```

### How to play
<p>The goal of this game is to collect all the collectibles, which are carrots in our case. Once you've collected all the carrots, you need to go and find your bunny friend to share the loot.</p>
<p>In the bonus part, there is a fox looking out for you though. Watch out!</p>

#### Controls
| Key | Action |
|---|---|
| <kbd>W</kbd>, <kbd>↑</kbd>| Move up |
| <kbd>S</kbd>, <kbd>↓</kbd>| Move down |
| <kbd>A</kbd>, <kbd>←</kbd>| Move to the left |
| <kbd>D</kbd>, <kbd>→</kbd>| Move to the right |
| <kbd>ESC</kbd>, `⎋`| Close the game |

## Project overview
<div align="center">
<img src="https://user-images.githubusercontent.com/101518532/235535445-db7cb863-fd05-439b-af49-a259f1343cac.gif" alt="Gameplay screenshot" width="830" height="416">
</div>

### Minilibx
This project had to be done using a simple graphic library called the MLX, which was provided with the subject. I have included the library here with my code but you can find more info on here: [https://harm-smits.github.io/42docs/libs/minilibx](https://harm-smits.github.io/42docs/libs/minilibx).

### Map requirements
* The map can only be composed of these characters:

| Description | Character|
|--|--|
| Empty space | `0` |
| Wall | `1` |
| Player | `P` |
| Exit | `E` |
| Collectible | `C` |
| Enemy | `F` |

* The map must be rectangular and surrounded by walls.
* The map has to be a .ber file. Not a folder. A file!
* The map must contain exactly one player and one exit, and at least one collectible. For the bonus map, you will also need an enemy.

## Bonus
<div align="center">
<img src="https://user-images.githubusercontent.com/101518532/235703038-8d4188d5-e9d7-4f3b-9892-e8e519673f91.gif" alt="Bonus gameplay screenshot" width="830" height="416">
<p><b>DON'T WORRY! NO BUNNIES WERE HARMED IN THE MAKING OF THIS GAME!</b></p>
</div>

## What I learned
