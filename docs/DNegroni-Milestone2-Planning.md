> Use this worksheet to plan the next phase of your project **before you begin coding**
> Be clear, specific, and intentional—this will guide your development this week.

---
Perfect. We can fill this out now based on where Crypt of the Damned actually stands and what your instructor wants us to improve for Milestone 2.

## 📌 Project Overview

**Project Name:**  
→ Crypt of the Damned

**What does your program currently do? (1–3 sentences)**  
→ Crypt of the Damned is a text-based C++ dungeon crawler with a working main menu and basic turn-based combat. The player can enter a name, fight a Skeleton Warrior, attack, defend, view stats and inventory, earn gold, and return to the main menu after combat.

---

## 🔍 Current Progress Check

**What is working right now?**  
→ The main menu, Player, Enemy, Item, and Game classes are working. The basic combat loop works, including attacking, defending, displaying player stats, displaying inventory, defeating an enemy, earning gold, and exiting the program normally.

**What is NOT working or incomplete?**  
→ The inventory system is not fully implemented because the player cannot currently use items during combat. Dungeon progression is also incomplete because the player only fights one enemy and does not yet move through multiple rooms or floors.

**What feels confusing or messy in your code?**  
→ The current input validation uses "std::cin.fail()", "clear()", and "ignore()". This works, but it is repetitive and could become messy as more menus are added. I want to replace it with a cleaner reusable validation method using try/catch based on the instructor feedback from Milestone 1.

---

## 🚀 Feature Planning

### Feature 1

**Name:**  
→ Improved Input Validation

**What does this feature do?**  
→ This feature will replace the current repeated stream-cleanup logic with a reusable input-validation method using try/catch. It will handle invalid menu input and give the user clear feedback without crashing or breaking the program flow.

**Why is this feature important?**  
→ It will make the program easier to use, improve error handling, and make the code cleaner as more menus and user choices are added.

---

### Feature 2

**Name:**  
→ Inventory and Item Usage

**What does this feature do?**  
→ This feature will allow the player to collect items, view them in the inventory, and use them during gameplay. The first usable item will likely be a healing potion that restores health.

**Why is this feature important?**  
→ The inventory currently exists but does not have meaningful gameplay functionality. Adding item usage will make the combat system more complete and give the player more choices.

---

### Feature 3 (optional)

**Name:**  
→ Dungeon Progression and Multiple Encounters

**What does this feature do?**  
→ This feature will allow the player to continue through multiple rooms or floors after defeating an enemy. Different enemies can appear as the player progresses.

**Why is this feature important?**  
→ Right now the game ends after a single encounter. Dungeon progression will make the program feel more like an actual dungeon crawler and give the game a stronger gameplay loop.

---

## 🧩 System Design Updates

**Will you need to create any new classes? If so, which ones?**  
→ I may create a Room or Dungeon class later to manage dungeon progression, room information, and enemy encounters. For this week, I may first expand the existing classes before adding a new class.

**Will you modify any existing classes? How?**  
→ Yes. I plan to modify the Game class to improve input validation and program flow. I will modify the Player class to support using items from the inventory, and the Item class may be expanded to support different item effects.

**What data structures will you use (vectors, 2D vectors, etc.)?**  
→ The Player class already uses a vector to store Item objects in the inventory. I may also use a vector of Enemy objects or room data later to support multiple encounters and dungeon progression.

---

## 🔄 Program Flow

**Describe how a user interacts with your program:**

1. Program starts →  
   The title and main menu are displayed.

2. User chooses →  
   The user can start the game, view player stats, view inventory, or exit.

3. Program responds →  
   If the game starts, the player enters a name and begins an enemy encounter. During combat, the player chooses actions such as attack, defend, view stats, or use inventory items.

4. Loop/next step →  
   The combat loop continues until the player or enemy is defeated. After winning, the player earns rewards and eventually continues to the next encounter or returns to the main menu.

---

## 🎯 Usability Improvements

**Clearer prompts:**  
→ I will make menu prompts more specific so the user always understands what input is expected and what each option does.

**Better error handling:**  
→ I will replace the current input validation with a reusable try/catch-based validation method that catches invalid input and allows the user to try again.

**Improved menu/navigation:**  
→ I will keep menus consistent and make sure the player can return to appropriate menus without getting stuck in a dead end.

---

## ⚠️ Potential Challenges

**What do you think will be the hardest part this week?**  
→ The hardest part will probably be replacing the existing input validation without breaking the current menu and combat flow. Expanding the inventory so items can be selected and used correctly may also require changes across several classes.

**What is your plan if you get stuck?**  
→ I will review the Day 3 lecture material, test one change at a time, compile frequently, and use debugging output to identify where problems occur. I will also review previous course examples and ask for clarification if needed.

---

## 📈 Level Up Goal

**What skill are you focusing on improving this week?**  
→ Input validation and error handling.

**What will you do to improve it?**  
→ I will review the lecture example using try/catch, practice creating reusable validation logic, test different invalid inputs, and apply the improved method throughout the program.

---

## 🗓️ Task Breakdown (GitHub Issues Planning)

- [ ] Replace menu input validation with reusable try/catch handling
- [ ] Add usable healing items to the inventory system
- [ ] Improve menu prompts and navigation flow
- [ ] Add dungeon progression with multiple enemy encounters

---

## 🔥 Final Check

- [x] Do I know what I’m building this week?
- [x] Do I know where to start?
- [x] Did I break my work into small tasks?

If yes → start coding 🚀

If no → refine your plan first

---

## 😈 Final Thought

> Plan it now… or debug it later.