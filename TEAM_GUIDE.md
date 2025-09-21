# 👥 Team Guide – Collaborazione sul Game Engine

Questa guida ti aiuterà a collaborare usando **GitHub** e **Visual Studio**.

---

## 🧭 1. Clonare il repository

### 🔹 In Visual Studio:
1. Apri Visual Studio
2. Vai su **File → Clone Repository**
3. Inserisci l’URL della repo GitHub
4. Seleziona la cartella di destinazione e clicca **Clone**

---

## 🌿 2. Creare un branch per ogni funzionalità

### 🔹 In Visual Studio:
1. Apri il pannello **Git Changes**
2. Clicca su **Current Branch → New Branch**
3. Dai un nome descrittivo al branch, es. `feature/input-system`
4. Clicca **Create and Checkout**

> 📌 Usa nomi coerenti: `feature/`, `fix/`, `docs/`, `refactor/`

---

## 🧪 3. Sviluppare e testare

- Scrivi il codice nel tuo branch
- Testa la funzionalità localmente
- Evita modifiche non necessarie ai file condivisi (es. `main.cpp`, `.sln`)

---

## 💬 4. Fare commit chiari

### 🔹 In Visual Studio:
1. Vai su **Git Changes**
2. Seleziona i file modificati
3. Scrivi un messaggio descrittivo, es. `"Aggiunto sistema di input con supporto tastiera"`
4. Clicca **Commit All**

---

## 📤 5. Push del branch su GitHub

### 🔹 In Visual Studio:
1. Dopo il commit, clicca su **Push**
2. Il branch verrà caricato su GitHub

---

## 📥 6. Aprire una Pull Request

### 🔹 Su GitHub:
1. Vai alla pagina della repository
2. Clicca su **Compare & Pull Request**
3. Compila la PR con:
   - Descrizione della funzionalità
   - Checklist (test, compilazione, note)
4. Clicca **Create Pull Request**

> ✍️ Il maintainer (tuo collega) revisionerà e farà il merge

---

## 🔄 7. Sincronizzare con il branch principale

### 🔹 In Visual Studio:
1. Vai su **Git Changes → Current Branch**
2. Seleziona `main` o `dev`
3. Clicca **Pull** per aggiornare il tuo codice locale

---

## ✅ Regole di collaborazione

- Non fare commit direttamente su `main`
- Crea sempre un branch per ogni modifica
- Scrivi messaggi di commit chiari e descrittivi
- Apri una PR per ogni funzionalità
- Comunica eventuali modifiche a file condivisi

