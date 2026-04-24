# Star Wars API - Movie Characters

This project contains a Node.js script that prints all characters of a Star Wars movie using the SWAPI endpoint.

## Project Information

- **Repository:** `holbertonschool-interview`
- **Directory:** `starwars_api`
- **Script:** `0-starwars_characters.js`

## Task Objective

Write a script that:

1. Takes a **Movie ID** as the first positional argument.
2. Fetches film data from SWAPI.
3. Prints each character name on a new line.
4. Preserves the exact order from the film endpoint `characters` list.

## Requirements

- Use the **Star Wars API**: [https://swapi-api.hbtn.io/](https://swapi-api.hbtn.io/)
- Use the **request** module.
- Output one character name per line.

## API Endpoints Used

- Film by ID:  
  `https://swapi-api.hbtn.io/api/films/<movie_id>/`
- Character resource URLs are read from the film JSON response.

Documentation: [https://swapi-api.hbtn.io/documentation](https://swapi-api.hbtn.io/documentation)

## Installation

From the `starwars_api` directory:

```bash
npm install request
```

## Usage

```bash
./0-starwars_characters.js <movie_id>
```

Example:

```bash
./0-starwars_characters.js 3
```

## Example Output (Movie ID: 3)

```text
Luke Skywalker
C-3PO
R2-D2
Darth Vader
Leia Organa
Obi-Wan Kenobi
Chewbacca
Han Solo
Jabba Desilijic Tiure
Wedge Antilles
Yoda
Palpatine
Boba Fett
Lando Calrissian
Ackbar
Mon Mothma
Arvel Crynyd
Wicket Systri Warrick
Nien Nunb
Bib Fortuna
```

## Implementation Notes

- The script performs the film request first.
- It then requests each character URL **sequentially** to keep output order consistent with SWAPI.
- If the movie ID is missing or the API response is invalid, the script exits quietly.

