let initTracking = [%raw
  {|
  function() {
    var script=document.createElement('script');
    script.type="text/javascript";
    script.src="https://www.googletagmanager.com/gtag/js?id=UA-128192260-1";
    document.body.appendChild(script);

    window.dataLayer = window.dataLayer || [];
    function gtag(){dataLayer.push(arguments);}
    gtag('js', new Date());

    gtag('config', 'UA-128192260-1', {
      'anonymize_ip': true,
      'cookie_expires': 0,
    });
  }
|}
];
