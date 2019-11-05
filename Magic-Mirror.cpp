//  Comments in /**/ are floof and may be skipped. Comments in // are game rules. Comments in //! TODO: are tasks you have to do

/* The Magic Kingdom was a place of prosperity and happiness, until one day the Magic Mirror was stolen! Today only
 * Ruins are left, and below them, the Dungeon. It is said, that the Magic Mirror is at the very bottom, protected by
 * Monsters and the Wicked Curse. You live in a Town nearby, working as a Monkey of Coding. One day you walk past the
 * Ruins and find a curious Black Key: */

#include <cassert>
#include <iostream>
#include <stdexcept>
#include <type_traits>

namespace Ruins {
	struct Black_Key {};
} // namespace Ruins

/* As you pick up the key you have a vision of delving down the Dungeon, fighting Monsters at compile time and at
 * runtime. You will return the Magic Mirror! But just being near the Wicked Curse saps your strength. */

// You are not allowed to use compiler flags such as -Dprivate=public to remove the challenge.

namespace Town {
	struct Blacksmith;
} // namespace Town

namespace Ruins {
	struct Dire_Wolf;
}
class Spider_Den;

/* You know the entrance to the ruins is guarded by a Dire Wolf, so you will need a weapon. */

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
		struct Master_Sword {};
		struct Training_Sword {};
		struct Wooden_Shield {};
		friend struct Ruins::Dire_Wolf;
		friend class ::Spider_Den;

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

/* Too bad you don't have any Money to buy that Master Sword, but the Back Entrance is unlocked, so you can sneak in the
 * back and steal the Training Sword! */

//! TODO: Define a variable named training_sword of type Town::Blacksmith::Training_Sword inside main

/* You will also need a shield. You know the Blacksmith keeps one under a Trap Door, but that is locked and you don't
 * have the key. Can you pick the lock? */

//! TODO: Define a variable named wooden_shield of type Town::Blacksmith::Wooden_Shield inside main

/* With the Training Sword you can go fight off the Dire Wolf guarding the
 * Entrance to the Ruins */

class Necromancer;

namespace Ruins {
	struct Dire_Wolf {
		private:
		struct Ruin_Entrance {};

		public:
		static void slay_wolf(int, int);
		static Ruin_Entrance slay_wolf(Town::Blacksmith::Training_Sword, Town::Blacksmith::Wooden_Shield) {
			return {};
		}
		friend class ::Necromancer;
	};
} // namespace Ruins

//! TODO: Define a variable named ruin_entrance of type Ruins::Dire_Wolf::Ruin_Entrance inside main using variable
//! training_sword from above

/* After slaying the wolf easy enough, you enter the Ruins. Inside you see a Necromancer, wearing the Key of Life. You
 * know you cannot beat the Necromancer. But maybe you can trick him. Mimic his evil magic so he believes that you are a
 * fellow Necromancer and just take it! */

class Foul_Magic {};

class Necromancer : Foul_Magic {
	friend class Thiefs;
	class Key_of_Life {
		Key_of_Life() {}
		friend Necromancer;
	};

	public:
	auto take(Foul_Magic *foul_magic, Ruins::Dire_Wolf::Ruin_Entrance) {
		if (not foul_magic or foul_magic != this) {
			throw std::runtime_error{"You are not a real Necromancer!"};
		}
		return Key_of_Life{};
	}
};

//! TODO: Define a variable named necromancer_key of type Necromancer::Key_of_Life inside main.

/* After taking the Key of Life you go towards the Dungeon. But before you can enter, you find yourself surrounded by a
 * group of Thieves. "We are here on orders of the Thieves Guild. Our spies report that you have a talent for magically
 * getting through locks." They continue "You were commissioned to produce a Skeleton Key that works on any lock. Also
 * we will be taking that Key of Life." They explain that you are not forced to comply and are free to choose death
 * instead. You think it might be better to do it. */

class Thiefs {
	class Secret_Location {
		struct Unknown_Key {};
		class Treasure {
			struct Coins {
				Coins(Coins &&) = default;

				private:
				Coins() {}
				Coins(const Coins &) = delete;
				friend class Treasure;
			} coins;
			Treasure() {}
			friend class Thiefs;
			friend class Thiefs_Shop;
		};
		static Treasure rob(Unknown_Key) {
			return {};
		}
		friend class Thiefs;
		friend class Thiefs_Shop;
	};
	friend class Thiefs_Shop;

	public:
	template <class Skeleton_Key>
	static auto comply(Necromancer::Key_of_Life, Skeleton_Key key) {
		auto treasure = Secret_Location::rob(key);
		return std::move(treasure.coins);
	}
};
//! TODO: Define a variable named coins of type Thiefs::Secret_Location::Treasure::Coins inside main.

/* That worked out well! Have some Coins as your reward. Let nobody say the Thieves Guild does not pay its employees.
 * We'll keep the rest safe. Since this worked so well, let's rob the Mages Guild! They are not so easy though. We tried
 * to use the Skeleton Key and it failed. But we learned that there are 2 checks made by the Lock: A Physical Check that
 * we already know to beat, and a Magical Check that defies our thief's tools. We ... convinced ... one of the mages to
 * give us a hand in breaking the Seal. Unfortunately we don't know how to apply it. That's where you come in. Of course
 * the Seal Breaker is not free, it'll cost you ... */

class Mages_Guild {
	class Seal_Breaker {
		Seal_Breaker() {}
		friend class Thiefs_Shop;
		// friend Mages_Tower;
	};
	struct Physical_Check {};
	struct Magic_Check {
		Magic_Check(Seal_Breaker) {}
	};
	struct Artefact {};
	static Artefact access(Physical_Check, Magic_Check) {
		return {};
	}
	friend class Thiefs_Shop;
	friend struct Layer;
};

class Thiefs_Shop {
	public:
	static Mages_Guild::Seal_Breaker buy(Thiefs::Secret_Location::Treasure::Coins &&coins) {
		(void)coins; /* gone is your money */
		return {};
	}
	template <class Seal_Breaker_Key>
	static auto rob_Mages_Guild(Seal_Breaker_Key key) {
		return Mages_Guild::access(key, key);
	}
};

/* The thief gives you a last hint:
 * "Before he die... I mean left us, the mage said you need some Seal Force Incantation Night Arcane Enchantment on the
 * key. No idea what that means." */

//! TODO: Define a variable named Artefact of type Mages_Guild::Artefact inside main.

/* "What a waste!" the Thief exclaims. "This thing does nothing. You can have it. I'm done with you!" You take the
 * Artefact and venture forth into the Dungeon.
 * As you explore the Dungeon, find 2 corridors, each containing a real Dragon! You can see that each Dragon guards a
 * key and you can almost reach it, but Magic keeps preventing you from reaching them. You must find a way to break
 * through! */

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

/* Now that you have obtained all the keys, it is time to claim your price! You can now go back to the Blacksmith in
 * Town and buy the Master Sword! */

struct Layer {
	static Inventory::Money loot_the_layer(Mages_Guild::Artefact, Adamantite_Dragon_Layer::Adamantite_Key,
										   Magic::Amethyst_Key) {
		return {};
	}
};

/* Using the Master Sword you push on. On your way you see a curious object. It seems like a piece of wood, but when you
 * look a second time it's a leaf, and after deliberately looking away and back it's a rock. At least you think it is,
 * there are many rocks here and you are not sure which one is the shape changer.
 */

struct Polymorph {};
class Change_Magic {
	private:
	Change_Magic() {}
	friend Change_Magic take(Polymorph);
};

Change_Magic take(Polymorph) {
	return {};
}

/* Them tricksy Polymorphs. */
template <class T>
void take(T);
extern int Polymorph;

//! TODO: Define a variable named change_magic of type Change_Magic in main.

/* You fight your way through a Spider Den. After cutting down spider webs for a while you see candle light. Inside the
 * Spider Den you find an old confused looking man. "I'm making strings! Help me make strings!" "Standard strings are
 * stupid! You can't tell how long they are just by looking at them! Enchant my strings so that I can!" How often do you
 * meet a weird old guy in a Spider Den wanting to make strings? May as well help. */

class Spider_Den {
	class Old_Man {
		class Magic_Lamp {
			Magic_Lamp() {}
			friend Old_Man;

			public:
			operator int() {
				std::cout << "Congratulations! You beat the demo! Now go buy the DLC with microtransactions.\n";
				return {};
			}
		} static magic_lamp;

		public:
		template <class Enchantment>
		Magic_Lamp &enchant_strings(Change_Magic) {
			static_assert(Enchantment::get_length("Some string") == sizeof("Some string"),
						  "I need to be able to see the length of my string!");
			static_assert(Enchantment::get_length("Some more string") == sizeof("Some more string"),
						  "I need to be able to see the length of my string!");
			assert(Enchantment::get_length(std::string{"Some string"}.c_str()) == sizeof("Some string"));
			assert(Enchantment::get_length(std::string{"Some more string"}.c_str()) == sizeof("Some more string"));
			return magic_lamp;
		}
	} static old_man;

	public:
	template <class Master_Sword>
	static Old_Man &free() {
		static_assert(std::is_same<Master_Sword, Town::Blacksmith::Master_Sword>::value,
					  "Your sword fails to cut the spider webs");
		return old_man;
	}
};
Spider_Den::Old_Man Spider_Den::old_man;
Spider_Den::Old_Man::Magic_Lamp Spider_Den::Old_Man::magic_lamp;

//! TODO: Define a variable named magic_lamp of type Spider_Den::Old_Man::Magic_Lamp inside main and return it.

// You are not allowed to change anything above this line:
//-----------------------------------------------------------------------------

int main() {
	//! TODO: uncomment the below lines and make them compile and run
	//auto training_sword = //Town::Blacksmith::Training_Sword
	//auto wooden_shield = //Town::Blacksmith::Wooden_Shield
	//auto ruin_entrance = //Ruins::Dire_Wolf::Ruin_Entrance
	//auto necromancer_key = //Necromancer::Key_of_Life
	//auto coins = //Thiefs::Secret_Location::Treasure::Coins
	//auto artefact = //Mages_Guild::Artefact
	//auto adamantite_key = //Adamantite_Dragon_Layer::Adamantite_Key
	//auto amethyst_key = //Magic::Amethyst_Key
	//auto money = //Inventory::Money
	//auto master_sword = //Town::Blacksmith::Master_Sword
	//auto change_magic = //Change_Magic
	//auto magic_lamp = //Spider_Den::Old_Man::Magic_Lamp
	//return magic_lamp;
}
