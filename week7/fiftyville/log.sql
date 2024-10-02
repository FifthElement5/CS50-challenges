-- Keep a log of any SQL queries you execute as you solve the mystery.
--looking for crime scene that matches the date and loctaion
SELECT description, id FROM crime_scene_reports
WHERE month = 7
AND day = 28
AND year = 2021
AND street = "Humphrey Street";

--looking through intervies
SELECT * FROM interviews
WHERE year = 2021
AND month = 7
AND day = 28
AND transcript LIKE "%bakery%";

--raport - 3  witnesses and bakery at 10:15
--witness Ruth
SELECT * FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute >=15 AND minute <=25;

--finding names from license-plate
SELECT name FROM people
WHERE license_plate IN (
SELECT license_plate FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute >=15 AND minute <=25);

--witness Eugene
SELECT account_number FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw";
--looking for name base on bank account
SELECT account_number, person_id FROM bank_accounts
WHERE account_number IN (
SELECT account_number FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw"
);
--select name base on person_id
SELECT name FROM people
WHERE id IN (
SELECT person_id FROM bank_accounts
WHERE account_number IN (
SELECT account_number FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw"
)
);
--WHO IS A THIEF: FINAL QUERY
SELECT name FROM people
WHERE license_plate IN (
SELECT license_plate FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute >=15 AND minute <=25)
AND id IN (
SELECT person_id FROM bank_accounts
WHERE account_number IN (
SELECT account_number FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw"
)
);
--witness Raymont
SELECT caller FROM phone_calls
WHERE duration < 60
AND year = 2021
AND month = 7
AND day = 28;
--looking for name
SELECT name FROM people
WHERE phone_number IN (
SELECT caller FROM phone_calls
WHERE duration < 60
AND year = 2021
AND month = 7
AND day = 28
);

SELECT name FROM people
WHERE license_plate IN (
SELECT license_plate FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute >=15 AND minute <=25)
AND id IN (
SELECT person_id FROM bank_accounts
WHERE account_number IN (
SELECT account_number FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw"
))
AND phone_number IN (
SELECT caller FROM phone_calls
WHERE duration < 60
AND year = 2021
AND month = 7
AND day = 28
);
--base on fligth
SELECT id FROM airports
WHERE full_name LIKE "%fiftyville";
--flights-id
SELECT id FROM flights
WHERE origin_airport_id IN (
SELECT id FROM airports
WHERE full_name LIKE "%fiftyville%"
)
AND year = 2021
AND month = 7
AND day = 29
AND hour < 12;
--passport_id
SELECT passport_number FROM passengers
WHERE flight_id IN (
SELECT id FROM flights
WHERE origin_airport_id IN (
SELECT id FROM airports
WHERE full_name LIKE "%fiftyville%"
)
AND year = 2021
AND month = 7
AND day = 29
AND hour < 12
);
SELECT name FROM people
WHERE passport_number IN (
SELECT passport_number FROM passengers
WHERE flight_id IN (
SELECT id FROM flights
WHERE origin_airport_id IN (
SELECT id FROM airports
WHERE full_name LIKE "%fiftyville%"
)
AND year = 2021
AND month = 7
AND day = 29
AND hour < 12
));
----WHO IS A THIEF: FINAL QUERY
SELECT name FROM people
WHERE license_plate IN (
SELECT license_plate FROM bakery_security_logs
WHERE year = 2021
AND month = 7
AND day = 28
AND hour = 10
AND minute >=15 AND minute <=25)
AND id IN (
SELECT person_id FROM bank_accounts
WHERE account_number IN (
SELECT account_number FROM atm_transactions
WHERE year = 2021
AND month = 7
AND day = 28
AND atm_location = "Leggett Street"
AND transaction_type = "withdraw"
))
AND phone_number IN (
SELECT caller FROM phone_calls
WHERE duration < 60
AND year = 2021
AND month = 7
AND day = 28
)
AND passport_number IN (
SELECT passport_number FROM passengers
WHERE flight_id IN (
SELECT id FROM flights
WHERE origin_airport_id IN (
SELECT id FROM airports
WHERE full_name LIKE "%fiftyville%"
)
AND year = 2021
AND month = 7
AND day = 29
AND hour < 12
));

--FINDING CITY
SELECT passport_number FROM people
WHERE name = "Bruce";
--Ffindig fligts id
SELECT flight_id FROM passengers
WHERE passport_number IN (
SELECT passport_number FROM people
WHERE name = "Bruce"
);
--SELECT destination_airport_id FROM flights
WHERE id IN (
SELECT flight_id FROM passengers
WHERE passport_number IN (
SELECT passport_number FROM people
WHERE name = "Bruce"
));

SELECT destination_airport_id FROM flights
WHERE id IN (
SELECT flight_id FROM passengers
WHERE passport_number IN (
SELECT passport_number FROM people
WHERE name = "Bruce"
));

--WHAT CITY: FINAL QUARY
SELECT city FROM airports
WHERE id IN (
SELECT destination_airport_id FROM flights
WHERE id IN (
SELECT flight_id FROM passengers
WHERE passport_number IN (
SELECT passport_number FROM people
WHERE name = "Bruce"
)));

--finding accomplice
SELECT phone_number FROM people
WHERE name = "Bruce";
SELECT receiver FROM phone_calls
WHERE caller IN (
SELECT phone_number FROM people
WHERE name = "Bruce"
)
AND year = 2021
AND month = 7
AND day = 28
AND duration < 60;

--finding name OF ACCOMPLICE: FINAL QUERY
SELECT name FROM people
WHERE phone_number IN (
SELECT receiver FROM phone_calls
WHERE caller IN (
SELECT phone_number FROM people
WHERE name = "Bruce"
)
AND year = 2021
AND month = 7
AND day = 28
AND duration < 60
);