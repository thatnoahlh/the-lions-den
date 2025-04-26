# The Lion's Den: Mental Health Interactive Environment

## Project Overview
This project is part of a 24-hour hackathon with the theme "Mind Matters: Tech for Mental Health and Well-being." It aims to create an interactive 3D environment centered around growing a flower. The growth of the flower symbolizes mental health progress and is influenced by three core elements:
- Journaling
- Answering mental health-related questions
- Playing engaging minigames

## Repository Structure
```
/src
  /journal
    journal.cpp       # Handles journaling functionality
  /questions
    questions.cpp     # Manages mental health-related questions
  /minigames
    minigame1.cpp     # First minigame
    minigame2.cpp     # Second minigame
  /3D_scene
    main.cpp          # Entry point for the 3D environment
    utilities.cpp     # Utility functions for rendering
    utilities.h       # Header file for utilities
```

## How It Works
1. **Journaling**: Users write journal entries that contribute to the flower's stem growth.
2. **Questions**: Answering questions about mental health adds colorful petals to the flower.
3. **Minigames**: Minigames enhance the environment and provide additional engagement.

## How to Build and Run
1. Clone the repository and navigate to the `n6` branch.
2. Compile the project using `g++` or your preferred C++ compiler.
3. Run the program to interact with the 3D environment.

## Future Plans
- Add more minigames to increase interactivity.
- Enhance the 3D rendering engine with realistic visuals.
- Incorporate user feedback into the design.
