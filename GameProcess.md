## Game Process
1. select race
2. initialization
3. command interpreter cycle
4. Game ends, Calculate Score, etc.

* * *

## Generation
generation happens in the following order: player character location, stairway location, potions, gold, enemies.
- potion (10 potions each floor)
	- each type has equal 1/6 possibility
- gold (10 piles each floor)
	- Normal: 5/8
	- Dragon Hoard: 1/8
	- Small: 2/8
- enemy (20 each floor, excluding dragons(D))
	- Human(H): 4/18
	- Dwarf(W): 3/18
	- Halfling(L): 18/5
	- Elf(E): 2/18
	- Orc(O): 2/18
	- Merchant(M): 2/18

## Combat
*Damage(Def ender) = ceiling((100/(100+Def (Def ender)))∗Atk(Attacker))*

| PC    | Stats    | Ability									|
|-------|----------|--------------------------------------------|
|Shade  |125 25 25 |Final score doubles  						|
|Drow   |150 25 15 |Potion effects magnified by 1.5				|
|Vampire|50 25 25  |Gain 5 HP every successful attack, no max HP|
|Troll  |120 25 15 |Gains 5 HP every turn						|
|Goblin |110 15 20 |Gains 5 gold for every enemy killed			|

| Enemy  | Stats    | Ability									    |
|--------|----------|---------------------------------------------- |
|Human   |140 20 20 |Drops two piles of Normal Gold				    |
|Dwarf   |100 20 30 |Vampires are allergic to them, -5HP every turn |
|Elf     |140 30 10 |Attack twice against every race except for drow|
|Orcs    |180 30 25 |Does 50% more damages to Goblines              |
|Merchant|30 70 5   |Drops merchant gold                            |
|Halfling|100 15 20 |50% chance to cause player to miss in combat   |
|Dragon  |150 20 20 |Guard Dragon Hoard, can attack at distance     | 

Upon their demise, any enemy that is not a dragon, human, or merchant will drop either a small pile or normal pile of gold. This gold is **immediately** added.

## Game Tik

Enemies should be moved in a *line-by-line* fashion.

