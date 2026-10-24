# 🚀 Welcome to Project & Portfolio!

This repository will be used to keep track of research and development conducted in this class. Follow the instructions below to get started.
cos
### Getting Started

**1.** Review the [About](./docs/01_about/README.md) README and all of the links it provides.

**2.** Review the documentation and [Getting Started](./docs/02_getting_started/README.md) steps in this repository's docs folder.

**3.** Attend the first Live Lecture to see a live setup demo. If you are unable to attend, make sure to watch the archive.

### Next Steps...

After completing the above steps, feel free to begin updating this readme where indicated below. Remember to update this document each week to receive proper credit for the weekly Milestone assignment.

<br>

> ❗️ &nbsp; Now that you have read to this point, go ahead and delete this sentence and everything above it.

<br>

# Project & Portfolio 1

### Student First & Last Name

Hello my name is [enter name]. I am a student from [where are you from?]. The purpose of this repository is to practice development using version control. This work will help me begin to build a portfolio of skills and accomplishment that can be shared in the future.

<br>

## 📢 &nbsp; Weekly Stand Up

Each week I will summarize my milestone activity and progress by writing a stand-up. A stand-up is meant to be a succinct update on how things are going. Use these prompts as a guide on what to write about:

⚙️ Overview - What I worked on this past week
<br>
🌵 Challenges - What problems did I have & how I'm addressing them
<br>
🏆 Accomplishments - What is something I "leveled up" on this week
<br>
🔮 Next Steps - What I plan to prioritize and do next

<br>

### Week 1

Overview

This week I focused on getting the foundation of my project set up correctly. I finished creating and configuring my GitHub repository, added the required starter files, created the main and dev branches, set up the GitHub Project board, and added the instructor to both the repository and the Project. I also cloned the repository locally and started building the core structure of Crypt of the Damned.

Challenges

The main challenge this week was getting familiar with the full GitHub workflow and making sure everything was organized the way the course requires. I also had to correct my workflow after accidentally committing some work to the main branch instead of dev, but I was able to merge the changes into dev and continue from there.

Accomplishments

One thing I improved on this week is project organization. I also created the initial class structure for the game, built a working menu and combat loop, tested the program successfully, and became more comfortable using branches, commits, Issues, and the Project board.

Next Steps

My next priority is to continue developing the inventory and item system, then begin working on dungeon progression and multiple encounters. I also plan to continue testing each feature as I add it and keep the Project board updated to reflect my progress.

### Week 2

Overview


This week I expanded Crypt of the Damned beyond the basic Milestone 1 foundation. I improved the input validation, added usable Healing Potions, created multiple dungeon encounters, added three different enemies, and added ASCII artwork and more atmospheric console output.

Challenges


One challenge was improving the input validation based on my Milestone 1 feedback. I replaced the previous stream cleanup approach with a reusable try/catch-based method. I also had an issue where using a Healing Potion appeared not to increase health because the enemy attacked immediately afterward. I changed the program flow so the updated health is shown clearly and the enemy does not attack during the item-use action.

Accomplishments


I became more comfortable with exception handling and reusable input validation. I also expanded the inventory system so items now have an actual gameplay purpose and built dungeon progression using multiple enemy encounters stored in a vector. The game now feels much closer to a complete dungeon crawler instead of a single combat demonstration.

Next Steps


For Week 3, I plan to continue expanding the game with additional items, enemies, and dungeon mechanics. I also want to keep improving usability, game balance, and the overall structure of the code as the project grows.

### Week 3

### Overview

This week I focused on improving both the gameplay and the organization of Crypt of the Damned. I addressed the instructor feedback from Milestone 2, added meaningful pointer usage, improved combat balance, refactored the combat system into smaller functions, and added more unique enemy behavior.

I also added new testing evidence and updated the Milestone 3 documentation to reflect the changes made to the project.

### Improvements

One major improvement was fixing the player reset system so health, gold, inventory, and defending state no longer carry over into a new game.

I also changed Healing Potions so using one now counts as the player's turn and allows the enemy to attack afterward.

The Defend system was improved significantly. Defending now has a 25% chance to completely block the enemy's attack and immediately counterattack for double damage. If the perfect block fails, the player still reduces the incoming damage by half.

The combat system was also refactored into smaller functions so the code is easier to read and maintain. Separate functions now handle combat status, menus, player actions, item use, defending, enemy turns, and combat results.

### Challenges

One challenge was making Defend useful without making it too powerful. The original version only reduced damage, which made attacking almost always the better choice. I changed it into a risk and reward system with a smaller chance for a Perfect Block and counterattack while keeping the normal half-damage defense.

Another challenge was adding pointer usage in a way that actually made sense for the program instead of adding a pointer only to satisfy the requirement. I used an Enemy pointer to track the current enemy being fought inside the dungeon.

### Accomplishments

One of my biggest accomplishments this week was becoming more comfortable refactoring existing code instead of only adding new features.

I also improved my understanding of pointers by using `currentEnemy` to directly reference the Enemy object being fought.

The combat system now feels more complete because Healing Potions are balanced, Defend has a meaningful purpose, damage feedback is clearer, and the Crypt Ghoul and Bone Knight have their own special attacks.

### Next Steps

Before Week 4, I plan to continue testing the game and fixing any remaining bugs or balance problems.

I also plan to review the project requirements for the final milestone and focus on the remaining features needed to make the program feel complete, including the File I/O and save/load requirements for the final version.

### Week 4

Overview

This week I focused on completing and polishing Crypt of the Damned for the final milestone.

I worked on balancing combat, improving the dungeon progression, adding a use for gold, expanding the class structure, and implementing File I/O.

What I Improved

Rebalanced the Perfect Block mechanic so it is useful without being too powerful.

Added a Grave Merchant shop where gold can be spent.

Added permanent Attack Power and Maximum Health upgrades.

Removed the free starting Healing Potion so the shop and gold economy matter more.

Expanded the dungeon from three floors to five floors.

Added the Grave Wraith and Crypt Lord.

Added new enemy special attacks.

Rebalanced later enemies and shop prices after testing showed the dungeon was too difficult.

Refactored display and input responsibilities into a separate GameUI class.

Added a RecordManager class for persistent File I/O and the Hall of Records.

Challenges

One of the biggest challenges this week was balancing the difficulty of the full dungeon.

After expanding the game to five floors, the later enemies were too difficult and I was consistently dying before reaching the end. I adjusted enemy health, attack damage, special attacks, and shop prices to make the difficulty progression more reasonable.

Another challenge was keeping Game.cpp maintainable as more features were added. I addressed this by moving display and input responsibilities into the GameUI class.

Accomplishments

I am most satisfied with the overall structure of the final project.

The game now has multiple interacting classes, meaningful pointer usage, a shop economy, permanent upgrades, unique enemy abilities, input validation, inventory management, five dungeon floors, and File I/O.

I also addressed the instructor feedback from previous milestones, including resetting player state, balancing Healing Potion turns, improving Perfect Block, giving gold a purpose, and reducing the responsibilities of Game.cpp.

Next Steps

The remaining work is focused on final testing and submission.

I still need to:

Complete final testing.

Capture final screenshots.

Confirm the Hall of Records persistence through a completed run.

Review the GitHub Project board.

Create and merge the final dev-to-main pull request.

Submit the final repository and Project board evidence.
