# 🎮 Cub3D

> 3D maze game using raycasting — C & MinilibX

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)
![42 Project](https://img.shields.io/badge/42-Project-000000?style=for-the-badge)
![Raycasting](https://img.shields.io/badge/Raycasting-Graphics-purple?style=for-the-badge)

---

## 🎯 About

Cub3D is a 42 school project that implements a 3D maze game using raycasting technology. This project teaches fundamental concepts of graphics programming, including:

- **Raycasting algorithm** — Casting rays from the player's perspective
- **Texture mapping** — Applying textures to walls
- **Sprite rendering** — Displaying objects in the 3D world
- **Player movement** — Keyboard controls for navigation
- **MinilibX** — 42's graphics library

---

## ✨ Features

- 🧱 **Textured walls** — Different textures for each wall type
- 🗺️ **Multiple maps** — Various maze configurations
- 🎮 **Player controls** — WASD for movement, mouse for looking
- 🚪 **Doors** — Interactive doors that open/close
- 💡 **Lighting effects** — Dynamic lighting based on distance
- 🎯 **Sprites** — Collectible items and decorations

---

## 🛠 Requirements

- C compiler (gcc or clang)
- MinilibX library
- Make

---

## ▶️ Usage

1. Clone the repository:
   ```bash
   git clone https://github.com/manugonz42/cub3d.git
   cd cub3d
   ```

2. Compile the project:
   ```bash
   make
   ```

3. Run the game:
   ```bash
   ./cub3D maps/map.cub
   ```

---

## 🗺️ Map Format

Maps are defined in `.cub` files with the following structure:

```
NO ./textures/north.png
SO ./textures/south.png
WE ./textures/west.png
EA ./textures/east.png

F 220,100,0
C 225,30,0

111111
100001
100001
111111
```

---

## 📚 Resources

- [Raycasting Tutorial](https://lodev.org/cgtutor/raycasting.html)
- [MinilibX Documentation](https://github.com/42Paris/minilibx-linux)
- [42 Project Subject](https://projects.intra.42.fr/)

---

## 🤝 Contributing

Contributions are welcome! Please read our [Contributing Guide](CONTRIBUTING.md) for details.

---

## 📄 License

This project is part of 42 School curriculum.

---

## 📫 Contact

Manuel González - [LinkedIn](https://linkedin.com/in/manugonz42) - manuel.gonzalez@example.com

Project Link: [https://github.com/manugonz42/cub3d](https://github.com/manugonz42/cub3d)
