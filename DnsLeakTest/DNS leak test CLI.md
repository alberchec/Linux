# DNS leak test CLI
A simple python-based CLI front end for [dnsleaktest.com](https://www.dnsleaktest.com/)

Usage details available with `-h`

Should run on most platforms as all modules are included in the standard python install

## How dnsleaktest.com works
When you visit [dnsleaktest.com](https://www.dnsleaktest.com/) and run a test, your browser attempts to load resources from randomly generated subdomains of test.dnsleaktest.com.

As these domains are random and unique, it is guaranteed that no response will be cached in any DNS servers, so when your device looks up the domains, the query will make its way back to an authoritative name server for dnsleaktest.com.

As these authoritative name servers are under the website's control, it can see when queries for the test domains come in.

The origin of the queries, being the DNS resursor that queries from your device end up at, is logged and at the end of the test, your browser asks dnsleaktest.com what servers it saw queries from for the random subdomains used in your test.

There's more information about fixing DNS leaks and the sneaky tricks that ISPs can pull to force you to use their DNS at [dnsleaktest.com](https://www.dnsleaktest.com/)


## To-Do:
- *Nothing currently*

## Changelog:
### v0.7
- Fix python <3.6 compatibility
### v0.6
- Add python3 compatibility
- Speed up tests
- General tidy-up of code & docs
### v0.5
- Implement 'identifiers' endpoint to pre-send UUID's to dnsleaktest.com
### v0.4
- Change lookup url for domains to be http, as the test domains now resolve, but to a server with an invalid HTTPS certificate.
### v0.3:
- Implement new API-based dnsleaktest
- **Breaking change:** JSON output does not use the same object/item names as previous version, as the result from the dnsleaktest API is just passed through
### v0.2:
- Add `-j`, `-s`, and `-p` options - JSON output support and DNS server specification via crude built-in DNS client
- Improve resiliency and error-handling
- Clean-up output
