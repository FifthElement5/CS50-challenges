--open file shows
sqlite3 shows.db

.schema

SELECT * FROM people;
SELECT * FROM people LIMIT 10;

SELECT * FROM stars LIMIT 10;

SELECT * FROM genres;
SELECT * FROM genres WHERE genre = 'Comedy';
--GIVES SHOW TITLE
SELECT * FROM shows WHERE id = 62614;

SELECT show_id FROM genres WHERE genre = 'Comedy';
SELECT COUNT(show_id) FROM genres WHERE genre = 'Comedy';

--shows title
SELECT title FROM shows WHERE id IN
(SELECT show_id FROM genres WHERE genre = 'Comedy') LIMIT 10;

SELECT title FROM shows WHERE id IN
(SELECT show_id FROM genres WHERE genre = 'Comedy') ORDER BY title LIMIT 10;

--finding Steve
SELECT * FROM people WHERE name = 'Steve Carell';
--finding shows that Steve played
SELECT * FROM stars WHERE person_id = 136797;
--finding what id = show
SELECT title FROM shows WHERE id = 115148;

--nesting
SELECT title FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (SELECT id FROM people WHERE name = 'Steve Carell')) ORDER BY title;

SELECT * FROM shows LIMIT 10;

SELECT * FROM shows JOIN genres ON shows.id = genres.show_id LIMIT 10;
SELECT * FROM shows JOIN genres ON shows.id = genres.show_id WHERE title = 'The Office';

SELECT * FROM shows JOIN ratings ON shows.id = ratings.show_id WHERE title = 'The Office';
--looking for Steve (expli)
SELECT title FROM people JOIN stars ON people.id = stars.person_id
JOIN shows ON stars.show_id = shows.id
WHERE name = 'Steve Carell';

--intp
SELECT title FROM people, stars, shows
WHERE people.id = stars.person_id
AND stars.show_id = shows.id
AND name = 'Steve Carell';
--wild card
SELECT * FROM people WHERE name LIKE 'Steve C%';
--indexes
.timer
.timer on
SELECT * FROM shows WHERE title = 'The Office';
CREATE INDEX title_index ON shows (title);


