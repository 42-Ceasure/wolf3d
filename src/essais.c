
// Uint32 		color2colorwallpsycho(t_ray *r, Uint32 color1, Uint32 color2)
// {
// 	Uint8 	a;
// 	Uint8 	ro;
// 	Uint8 	g;
// 	Uint8 	b;

// 	r->c_a1 = (color1 & 0xFF000000) >> 24;
// 	r->c_r1 = (color1 & 0x00FF0000) >> 16;
// 	r->c_g1 = (color1 & 0x0000FF00) >> 8;
// 	r->c_b1 = (color1 & 0x000000FF);
// 	r->c_a2 = (color2 & 0xFF000000) >> 24;
// 	r->c_r2 = (color2 & 0x00FF0000) >> 16;
// 	r->c_g2 = (color2 & 0x0000FF00) >> 8;
// 	r->c_b2 = (color2 & 0x000000FF);
// 	a = 0;
// 	ro = r->c_r1 + (r->y) * (r->c_r2 - r->c_r1)/(r->stop - r->start);
// 	g = r->c_g1 + (r->y) * (r->c_g2 - r->c_g1)/(r->stop - r->start);
// 	b = r->c_b1 + (r->y) * (r->c_b2 - r->c_b1)/(r->stop - r->start);
// 	if (r->side == 1 && r->y > r->drawstart)
// 	{
// 		a = 0x00;
// 		ro /= 1.2;
// 		g /= 1.2;
// 		b /= 1.2;
// 	}
// 	return ((((((a << 8) + ro) << 8) + g) << 8)+ b);
// }

// Uint32 		color2colorwallchelou(t_ray *r, Uint32 color1, Uint32 color2)
// {
// 	Uint8 	a;
// 	Uint8 	ro;
// 	Uint8 	g;
// 	Uint8 	b;

// 	r->c_a1 = (color1 & 0xFF000000) >> 24;
// 	r->c_r1 = (color1 & 0x00FF0000) >> 16;
// 	r->c_g1 = (color1 & 0x0000FF00) >> 8;
// 	r->c_b1 = (color1 & 0x000000FF);
// 	r->c_a2 = (color2 & 0xFF000000) >> 24;
// 	r->c_r2 = (color2 & 0x00FF0000) >> 16;
// 	r->c_g2 = (color2 & 0x0000FF00) >> 8;
// 	r->c_b2 = (color2 & 0x000000FF);
// 	a = 0;
// 	ro = r->c_r1 + (r->y - r->start) * (r->c_r2 - r->c_r1)/(r->stop - (float)r->y);
// 	g = r->c_g1 + (r->y - r->start) * (r->c_g2 - r->c_g1)/(r->stop - (float)r->y);
// 	b = r->c_b1 + (r->y - r->start) * (r->c_b2 - r->c_b1)/(r->stop - (float)r->y);
// 	if (r->side == 1 && r->y > r->drawstart)
// 	{
// 		a = 0x00;
// 		ro /= 1.2;
// 		g /= 1.2;
// 		b /= 1.2;
// 	}
// 	return ((((((a << 8) + ro) << 8) + g) << 8)+ b);
// }
