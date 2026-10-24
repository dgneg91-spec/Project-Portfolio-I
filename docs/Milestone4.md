Overview

For Milestone 4, I focused on completing the final version of Crypt of the Damned, improving combat balance, giving gold a meaningful purpose, expanding the dungeon, refactoring the project structure, and adding persistent File I/O.

The goal of this milestone was to turn the prototype into a more complete and maintainable console game while also addressing the instructor feedback from previous milestones.

Final Gameplay Improvements

The dungeon was expanded from three floors to five floors.

The final enemy progression is:

Skeleton Warrior

Crypt Ghoul

Bone Knight

Grave Wraith

Crypt Lord

Each floor becomes progressively more difficult, and several enemies have unique special attacks.

The Crypt Ghoul can use Savage Claw.

The Bone Knight can use Crushing Blow.

The Grave Wraith can use Soul Drain.

The Crypt Lord can use Dark Execution.

This gives the enemies more variety instead of having every enemy behave exactly the same.

Perfect Block Rebalancing

The Perfect Block mechanic was changed after instructor feedback.

Previously, a successful Perfect Block allowed the player to immediately deal double damage while preventing the enemy from completing its attack.

This made defending too powerful.

The updated system keeps the 25% Perfect Block chance, but the enemy still performs its attack.

If a Perfect Block succeeds:

The player takes 0 damage.

The enemy's attack is blocked.

The player performs a counterattack using normal attack damage.

If the Perfect Block fails, the normal Defend mechanic still reduces incoming damage.

This keeps Defend useful without making it stronger than normal attacking.

Gold and Shop System

Gold now has a meaningful purpose.

A new Shop class was created for the Grave Merchant.

The shop appears between dungeon floors and allows the player to spend gold earned from defeating enemies.

The player can purchase:

Healing Potion – restores health.

Sharpen Weapon – permanently increases Attack Power.

Vitality Blessing – permanently increases Maximum Health and restores health.

The shop system creates more decisions during the dungeon because the player must decide whether to spend gold on healing or save it for permanent upgrades.

The free starting Healing Potion was also removed so that items and gold have more value during the run.

Dungeon Balance

The dungeon was rebalanced after testing showed that the later enemies were too difficult.

Enemy health, attack damage, and special attack damage were reduced.

Shop upgrade prices were also reduced so that upgrades are realistically affordable during a normal run.

The purpose of these changes was to create a difficulty curve that becomes harder each floor without requiring a nearly perfect run.

GameUI Refactor

Game.cpp had grown large and was responsible for too many different systems.

To improve maintainability, a new GameUI class was created.

GameUI now handles:

Title screen output.

Main menu output.

Enemy ASCII art.

Victory screen.

Death screen.

Combat status display.

Combat menu display.

Menu input validation.

This allows the Game class to focus more on game flow, combat, dungeon progression, and coordinating the other classes.

Class Responsibilities

The final project now separates responsibilities across several classes.

Game

Controls the main game loop, dungeon progression, combat flow, and interactions between the game's systems.

Player

Stores and manages player health, maximum health, attack power, gold, inventory, defending state, and upgrades.

Enemy

Stores enemy statistics and handles enemy-specific attack behavior.

Item

Stores information about usable items such as Healing Potions.

Shop

Handles Grave Merchant purchases and gold spending.

GameUI

Handles menus, ASCII art, game output, and validated menu input.

RecordManager

Handles persistent File I/O for completed dungeon runs.

Pointer Usage

The project uses an Enemy pointer called currentEnemy.

The pointer references the enemy currently being fought from the enemy vector.

This allows the combat system to interact with the current enemy without creating another copy of the Enemy object.

The pointer is also checked against nullptr before combat begins.

File I/O

A RecordManager class was added to provide persistent File I/O.

Successful dungeon runs are written to a text file using std::ofstream.

The saved information includes:

Player name.

Remaining gold.

Final Attack Power.

Current Health.

Maximum Health.

The Hall of Records option uses std::ifstream to read saved records back from the file and display them to the player.

The record file uses append mode so previous successful runs are not overwritten.

The Hall of Records system is implemented, although a complete victory-based persistence test was still pending during final testing because the full dungeon had not yet been successfully completed.

Input Validation

Menu input continues to use reusable validation based on:

std::getline

std::stoi

try/catch

invalid_argument

out_of_range

This prevents invalid text, extra characters, and menu choices outside the valid range from breaking the program.

Final Testing

The game was compiled and run repeatedly throughout development.

Testing included:

Starting a new game.

Player reset behavior.

Combat.

Normal attacks.

Defending.

Perfect Blocks.

Healing Potion usage.

Invalid input.

Inventory display.

Player stat display.

Enemy special attacks.

Shop purchases.

Insufficient gold.

Attack upgrades.

Maximum Health upgrades.

Five-floor dungeon progression.

Hall of Records menu access.

File creation and File I/O implementation.

Additional gameplay balancing was performed after testing showed that the final floors were too difficult.

Final Result

Crypt of the Damned now includes a complete multi-floor dungeon, five enemy encounters, unique enemy attacks, turn-based combat, inventory management, defensive mechanics, a shop economy, permanent upgrades, validated input, meaningful pointer usage, File I/O, ASCII artwork, and improved class organization.
