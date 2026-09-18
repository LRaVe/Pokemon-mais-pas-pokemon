Review Code Lucas par Mohammed :

Dans cette review, je classe les remarques par ordre d'importance, en fonction de l'impact :

- **Critic** :
    - **Gérer les exceptions** : (Pokemon_Attack.cpp l17,28| Pokemon_Party l23, 36 |Pokedex l49,58)
Est-ce une bonne idée de retourner une exception runtime si le pokemon n'est pas trouvé ? Je trouve cela exagéré de faire crasher le programme car un pokémon n'est pas trouvé dans l'index. Mettre dans un try and Catch.

---

- **Hard** : 

    - Ne pas mettre de test dans le main mais créer une classe à part.
    - Il faudrait ajouter des commentaires sur tes fonctions, au format JAVADOC, en précisant en une phrase ce que fait la fonction, ce qu'elle prend et ce qu'elle renvoie. 

    - Ajouter ce que tu as mis dans le README au sujet des classes en commentaire au début de la classe.

---

- **Medium** : 

    - Pas de code commenté dans ta version finale, ça pollue ton code et c'est utile pour un débug "à la main" (main.cpp l37 l39 | Pokedex.cpp l24 |Pokemon.cpp l22)

    - Ajouter une gestion d'erreur si le fichier pokedex n'est pas trouvé (avec des exceptions)

---

- **Low** :

    - Ne pas écrire des fonctions qui font 2 choses, si tu veux écrire dans la console (cf ) crée une classe Interface (meme si c'est que le terminal) et adapte la signature de ta fonction (retour booléen) pour écrire sur la console en fonction du résultat de ta première fonction

    - Remarque (SetofPokemon.cpp l15) : Comment trouver les évolutions à partir de l'ID puisque le code cherche uniquement la première occurence ? (peut-être qu'il faut utilser findByName alors...)

---

Bons réflexes :

- Classes bien structurées, bien organisées, assez courtes.
- Existence d'un Fichier gérant les url (Code plus lisible)
- README clair, mais peut-être ajouter un paragraphe sur les utilisateurs LINUX
- Code très propre.

