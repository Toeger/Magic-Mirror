# Magic-Mirror
Play a C++ puzzle text adventure (?), defeat monsters at compiletime and runtime, and return the Magic Mirror!

## How to play
Copy the contents of [Magic-Mirror.cpp](https://raw.githubusercontent.com/Toeger/Magic-Mirror/master/Magic-Mirror.cpp) into your IDE or a website like https://coliru.stacked-crooked.com, uncomment the comments inside `main` and get the code to compile and run.

## I don't get it, the code doesn't do anything
Correct. The point is to find a way to get at the more or less hidden types required to progress.

Step 1 is to uncomment `[[maybe_unused]] auto training_sword =` and find a way to get it. The solution is `[[maybe_unused]] auto training_sword = Town::Blacksmith::steal_Training_Sword(Town::Blacksmith::Back_Entrance{});`.  
Step 2 is to steal the `Wooden_Shield`.  
Step 3 is to call `Ruins::Dire_Wolf::slay_wolf` with your equipment to get the `Ruin_Entrance`. Continue until you return the `master_sword` (for now).

## I'm stuck! Help!
You are probably missing some more or less obscure C++ feature. Some of the following might help:
https://en.cppreference.com/w/cpp/language/list_initialization  
https://en.cppreference.com/w/cpp/language/friend  
https://en.cppreference.com/w/cpp/language/adl  

## I did it! Should I show everyone my solution?
Congratulations! Please don't. Puzzles are no fun when the solution is spoiled.
