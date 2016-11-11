SELECT CONCAT('https://', b.subdomain, '/node/', a.nid) AS url FROM domain_access a INNER JOIN domain b ON a.gid = b.domain_id INNER JOIN node c ON a.nid = c.nid ORDER BY url;
