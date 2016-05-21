The `server.js` listed in the masters thesis included a PostgreSQL client connection string
which was specific to my environment. The server.js listed here will instead prompt for a
`config.json` file containing the password. Since this change only affects the web server
startup and not the processing of requests, it should make no difference for our results.
