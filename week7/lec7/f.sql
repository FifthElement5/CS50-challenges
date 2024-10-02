sqlite3 favorites.db

.mode csv
.import favorites.csv favorites
.schema

SELECT * FROM favorites;
SELECT COUNT(*) FROM favorites;

SELECT DISTINCT(language) FROM favorites;

--counts language
SELECT COUNT(DISTINCT(LANGUAGE)) FROM favorites;

--creats tiny table
SELECT COUNT(DISTINCT(language)) AS n FROM favorites;

--check how many like C
SELECT COUNT(*) FROM favorites WHERE language = 'C';
SELECT COUNT(*) FROM favorites WHERE language = 'C'AND problem = 'Mario';

SELECT language, COUNT(*) FROM favorites GROUP BY language;
SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*);
SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*) DESC;
SELECT language, COUNT(*) FROM favorites GROUP BY language ORDER BY COUNT(*) DESC LIMIT 1;

--inserting into database
INSERT INTO favorites (language, problem) VALUES('SQL', 'Fiftyvile');

SELECT * FROM favorites WHERE language = 'C';
UPDATE favorites SET language = 'C++' WHERE language = 'C';

DELETE FROM favorites WHERE problem = 'Tideman';
