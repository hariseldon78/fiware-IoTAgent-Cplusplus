curl -X DELETE 'http://127.0.0.1:8080/iot/services?apikey=NEWapikey&resource=/iot/test' \
    -i \
		-H "Fiware-Service: testservice" \
		-H "Fiware-ServicePath: /testsubservice"
