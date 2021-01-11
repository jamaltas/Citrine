#pragma once

#include "Citrine/Layer.h"

#include "Citrine/Events/ApplicationEvent.h"
#include "Citrine/Events/KeyEvent.h"
#include "Citrine/Events/MouseEvent.h"

namespace Citrine {

	class CITRINE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}