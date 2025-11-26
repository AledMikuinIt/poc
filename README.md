# Projet Resource Manager avec pointer-chasing et analyse micro-architecturale 

---

## **Objectif général**

Créer un **gestionnaire de ressources basé sur des pointeurs multiples**, avec différents niveaux d’indirection, puis **analyser l’impact de la structure mémoire sur la performance CPU** (latence, TLB misses, cache behavior).

---

# **Plan détaillé avec étapes et milestones**

---

## **Phase 0 : Préparation (1 semaine)**

**Objectifs :**

- Définir ton environnement de travail (Linux recommandé pour `perf` ou un équivalent).
- Choisir le langage (C ou C++ idéal pour pointer-chasing bas niveau).
- Déterminer les outils de mesure : high-resolution timer + compteur matériel (perf, VTune ou equivalent).

**Milestone 0 :**

- Repo GitHub créé avec README initial expliquant le projet et les objectifs.
- Environnement prêt et testé (timers, compilation, perf).

---

## **Phase 1 : Design du Resource Manager (2–3 semaines)**

**Objectifs :**

- Concevoir le **Resource Manager** :
    - Tableau de handles (un array de pointeurs).
    - Chaque handle pointe vers un objet.
    - Chaque objet contient plusieurs pointeurs (next, alt, meta…).
- Dessiner la **structure de données** : graphe de pointeurs multi-niveau.
- Définir les tailles de structures et alignements mémoire pour expérimentations.

**Milestone 1 :**

- Diagramme complet de la structure (README + schéma).
- Code initial pour allouer le Resource Manager et remplir les objets (même si les traversées ne sont pas encore implémentées).

---

## **Phase 2 : Pointer-chasing simple (1–2 semaines)**

**Objectifs :**

- Implémenter une **traversée séquentielle** :
    - Suivre next → next → … jusqu’à la fin.
- Ajouter des variantes :
    - Traversée linéaire (array simple)
    - Traversée avec indirection multiple (double pointer, alt, meta)
- S’assurer que la traversée respecte **la dépendance sérieuse** (le CPU doit attendre chaque pointeur).

**Milestone 2 :**

- Traversée fonctionnelle du graphe complet.
- Timer intégré pour mesurer **latence brute** des traversées.
- README mis à jour avec exemples de traversée et schéma des patterns.

---

## **Phase 3 : Pointer-chasing avancé + variations mémoire (2–3 semaines)**

**Objectifs :**

- Créer **des patterns d’accès mémoire variés** :
    - Graphe packé (plusieurs objets par page)
    - Graphe éparpillé (un objet par page)
    - Permutation aléatoire
- Préparer les **benchmarks pour comparer** les latences.
- Vérifier les **dépendances sérieuses** pour empêcher le CPU de réordonner.

**Milestone 3 :**

- Trois patterns différents implémentés et traversables.
- Latence brute mesurée pour chaque pattern.
- Graphiques simples montrant les différences.

---

## **Phase 4 : Analyse micro-architecturale (1–2 semaines)**

**Objectifs :**

- Ajouter mesures TLB / cache / branch misses via outils type `perf`.
- Collecter :
    - TLB load / store misses
    - L1/L2/L3 cache misses
    - Branch mispredictions (si applicable)
- Visualiser comment les patterns d’accès impactent ces métriques.

**Milestone 4 :**

- Tableau ou graphique des résultats.
- Interprétation claire : “ce pattern provoque des TLB misses, celui-ci pas”.
- README mis à jour avec **analyse des effets micro-architecturaux**.

---

## **Phase 5 : Documentation et synthèse (1–2 semaines)**

**Objectifs :**

- Rédiger un **README 3–6 pages** bien structuré :
    1. Objectif du projet
    2. Conception du Resource Manager
    3. Traversées et patterns
    4. Résultats de latence
    5. Analyse micro-architecturale (TLB, cache, pipeline)
    6. Conclusion + pistes futures
- Préparer un **résumé 1 page** pour la candidature Télécom Paris.

**Milestone 5 :**

- README complet, schémas, graphiques.
- Résumé prêt pour candidature.
- Code dans GitHub fonctionnel et propre.

---

## **Phase 6 (bonus, si tu as du temps)**

- Expérimenter avec :
    - Variations de tailles de pages ou alignement mémoire.
    - Plus de niveaux de pointeurs (triple pointeur, graphes plus profonds).
    - Comparaison des performances sur plusieurs machines / architectures.
- Ajouter un **schéma “impact CPU”** : comment le pattern d’accès influence TLB, cache, pipeline.

**Milestone 6 :**

- Graphiques comparatifs avancés.
- README enrichi avec observations “hardware-aware”.

# **Résumé des Milestones pour GitHub / candidature**

| Milestone | Objectif clé | Livrable visible |
| --- | --- | --- |
| 0 | Préparation & repo | README initial + environnement prêt |
| 1 | Design Resource Manager | Diagramme + allocation des objets |
| 2 | Traversée simple | Traversée fonctionnelle + latence brute |
| 3 | Variations mémoire | Patterns multiples + premiers graphiques |
| 4 | Analyse micro-archi | Tableaux/graphes TLB, cache, branches |
| 5 | Documentation | README final + résumé 1 page |
| 6 | Bonus avancé | Graphiques comparatifs multi-niveaux & machines |