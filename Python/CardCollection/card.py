import json
from json import JSONEncoder

class MtGCard:
    """Represents a card in the card collection. Match against card details in searches."""

    def __init__(self, card_name, mana, types, rules_text, stats, set_details, rarity):
        self.card_name = card_name
        self.mana = mana
        self.types = types
        self.rules_text = rules_text
        self.stats = stats
        self.set_details = set_details
        self.rarity = rarity

class Mana:
    """Colored mana cost and converted mana cost. For example: 2BB, 4."""

    def __init__(self, cost, cmc):
        self.cost = cost
        self.cmc = cmc

class Types:
    """Card type and subtype. For example: Creature - Goblin."""
    #TODO: Parser and formatter (Always uppercase and separator) 
    def __init__(self, types, subtypes):
        self.types = types
        self.subtypes = subtypes

class SetDetails:
    """Expansion and card number. For example: Theros, 120."""

    def __init__(self, expansion, card_number):
        self.expansion = expansion
        self.card_number = card_number

class CardEncoder(JSONEncoder):
        def default(self, o):
            return o.__dict__

mana = Mana("1G", 2)
types = Types("Creature", "Snake")
rules_text = "Landfall - Whenever a land enters the battlefield under your control, add one mana of any color."
set_details = SetDetails("Zendikar Rising", 193)
snek = MtGCard("Lotus Cobra", mana, types, rules_text, "2/1", set_details, "Rare")

print(CardEncoder().encode(snek))

cardJSONData = json.dumps(snek, indent=4, cls=CardEncoder)
print(cardJSONData)