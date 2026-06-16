import importlib

print("=== Kaboom 1 ===")
print("Access to alchemy/grimoire/dark_spellbook.py directly")
print("Test import now - THIS WILL RAISE AN UNCAUGHT EXCEPTION")

dark_spellbook = importlib.import_module("alchemy.grimoire.dark_spellbook")
dark_spell_record = dark_spellbook.dark_spell_record
result = dark_spell_record("Shadow", "bats and eyeball")
print(f"Testing record dark spell: {result}")
