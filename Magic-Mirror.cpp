//  Comments in /**/ are floof and may be skipped. Comments in // are game rules. Comments in //! TODO: are tasks you have to do

/* The Magic Kingdom was a place of prosperity and happiness, until one day the Magic Mirror was stolen!
 * Today only Ruins are left, and below them, the Dungeon. It is said, that the Magic Mirror is at the very bottom, protected by Monsters and the Wicked Curse.
 * You live in a Town nearby, working as a Monkey of Coding. One day you walk past the Ruins and find a curious Black Key: */

#include <iostream>
#include <stdexcept>
#include <type_traits>

namespace Ruins {
	struct Dire_Wolf;
	struct Black_Key {};
} // namespace Ruins

/* As you pick up the key you have a vision of delving down the Dungeon, fighting Monsters at compile time and at runtime.
 * You will return the Magic Mirror!
 * But just being near the Wicked Curse saps your strength. */

//You are not allowed to use compiler flags such as -Dprivate=public to remove the challenge.

namespace Town {
	struct Blacksmith;
	struct Rusty_Key {};
} // namespace Town

/* You know the entrance to the ruins is guarded by Monsters, so you will need a weapon. */

class Inventory {
	friend struct Town::Blacksmith;
	friend struct Layer;
	class Money {
		friend struct Layer;
		Money() {}
	};
};

namespace Town {
	struct Blacksmith {
		struct Back_Entrance {};

		private:
		struct Storage_Key {};
		struct Master_Sword {
			operator int() {
				return {};
			}
		};
		struct Training_Sword {};
		struct Wooden_Shield {};
		friend struct Ruins::Dire_Wolf;

		public:
		static Master_Sword buy_Master_Sword(Inventory::Money) {
			return {};
		}
		static Training_Sword steal_Training_Sword(Back_Entrance) {
			return {};
		}
		static Wooden_Shield steal_Wooden_Shield(Storage_Key) {
			return {};
		}
	};
} // namespace Town

/* Too bad you don't have any Money to buy that Master Sword, but the Back Entrance is unlocked, so you can sneak in the back and steal the Training Sword! */

//! TODO: Define a variable named training_sword of type Town::Blacksmith::Training_Sword inside main

/* You will also need a shield. You know the Blacksmith keeps one under a Trap Door, but that is locked and you don't have the key. Can you pick the lock? */

//! TODO: Define a variable named wooden_shield of type Town::Blacksmith::Wooden_Shield inside main

/* With the Training Sword you can go fight off the Dire Wolf guarding the Entrance to the Ruins */

namespace Ruins {
	struct Dire_Wolf {
		private:
		struct Ruin_Entrance {};

		public:
		static void slay_wolf(int, int);
		static Ruin_Entrance slay_wolf(Town::Blacksmith::Training_Sword, Town::Blacksmith::Wooden_Shield) {
			return {};
		}
	};
} // namespace Ruins

//! TODO: Define a variable named ruin_entrance of type Ruins::Dire_Wolf::Ruin_Entrance inside main using variable training_sword from above

/* After slaying the wolf easy enough, you enter the Ruins. Inside you see a Necromancer, wearing the Key of Life.
 * You know you cannot beat the Necromancer. But maybe you can trick him.
 * Mimic his evil magic so he believes that you are a fellow Necromancer and just take it! */

class Foul_Magic {};

class Necromancer : Foul_Magic {
	class Key_of_Life {
		Key_of_Life() {}
		friend Necromancer;
	};

	public:
	auto take(Foul_Magic *foul_magic) {
		if (foul_magic != this) {
			throw std::runtime_error{"You are not a real Necromancer!"};
		}
		return Key_of_Life{};
	}
};

//! TODO: Define a variable named necromancer_key of type Necromancer::Key_of_Life inside main.

/* After taking the Key of Life you enter the Ruins and are met with 2 corridors, each containing a real dragon!
 * You can see that each dragon guards a key and you can almost reach it, but Magic keeps preventing you from reaching them.
 * You must find a way to break through! */

struct Adamantite_Dragon_Layer {
	friend struct Layer;

	private:
	class Adamantite_Key {
		Adamantite_Key() {}
		friend Adamantite_Dragon_Layer::Adamantite_Key break_magic();
	};
	Adamantite_Dragon_Layer() = delete;
	friend Adamantite_Key break_magic() {
		return {};
	}
};

//! TODO: Define a variable named adamantite_key of type Adamantite_Dragon_Layer::Adamantite_Key inside main.

class Magic {
	friend struct Amethyst_Dragon_Layer;
	friend struct Layer;
	class Amethyst_Key {
		Amethyst_Key() {}
		friend Magic::Amethyst_Key break_magic(void *);
	};
};

struct Amethyst_Dragon_Layer final {
	private:
	Amethyst_Dragon_Layer() = delete;
	friend Magic::Amethyst_Key break_magic(void *) {
		return {};
	}
};

//! TODO: Define a variable named amethyst_key of type Magic::Amethyst_Key inside main.

/* Now that you have obtained all the keys, it is time to claim your price! */

struct Layer {
	static Inventory::Money loot_the_layer(Adamantite_Dragon_Layer::Adamantite_Key, Magic::Amethyst_Key) {
		return {};
	}
};

//You are not allowed to change anything above this line:
//-----------------------------------------------------------------------------

int main() {
	//! TODO: uncomment the below lines and make them compile and run
	//[[maybe_unused]] auto training_sword =
	//[[maybe_unused]] auto wooden_shield =
	//[[maybe_unused]] auto ruin_entrance =
	//[[maybe_unused]] auto necromancer_key =
	//[[maybe_unused]] auto adamantite_key =
	//[[maybe_unused]] auto amethyst_key =
	//auto money = Layer::loot_the_layer(adamantite_key, amethyst_key);
	//auto master_sword = Town::Blacksmith::buy_Master_Sword(money);
	//return master_sword
}
